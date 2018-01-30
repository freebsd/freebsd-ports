--- subversion/libsvn_subr/gpg_agent.c.orig	2016-11-14 04:00:09 UTC
+++ subversion/libsvn_subr/gpg_agent.c
@@ -65,9 +65,12 @@
 #include <sys/un.h>
 
 #include <apr_pools.h>
+#include <apr_strings.h>
+#include <apr_user.h>
 #include "svn_auth.h"
 #include "svn_config.h"
 #include "svn_error.h"
+#include "svn_io.h"
 #include "svn_pools.h"
 #include "svn_cmdline.h"
 #include "svn_checksum.h"
@@ -225,30 +228,31 @@ bye_gpg_agent(int sd)
   close(sd);
 }
 
-/* Locate a running GPG Agent, and return an open file descriptor
- * for communication with the agent in *NEW_SD. If no running agent
- * can be found, set *NEW_SD to -1. */
-static svn_error_t *
-find_running_gpg_agent(int *new_sd, apr_pool_t *pool)
+/* This implements a method of finding the socket which is a mix of the
+ * description from GPG 1.x's gpg-agent man page under the
+ * --use-standard-socket option and the logic from GPG 2.x's socket discovery
+ * code in common/homedir.c.
+ *
+ * The man page says the standard socket is "named 'S.gpg-agent' located
+ * in the home directory."  GPG's home directory is either the directory
+ * specified by $GNUPGHOME or ~/.gnupg.  GPG >= 2.1.13 will check for a
+ * socket under (/var)/run/UID/gnupg before ~/.gnupg if no environment
+ * variables are set.
+ *
+ * $GPG_AGENT_INFO takes precedence, if set, otherwise $GNUPGHOME will be
+ * used.  For GPG >= 2.1.13, $GNUPGHOME will be used directly only if it
+ * refers to the canonical home -- ~/.gnupg.  Otherwise, the path specified
+ * by $GNUPGHOME is hashed (SHA1 + z-base-32) and the socket is expected to
+ * be present under (/var)/run/UID/gnupg/d.HASH. This last mechanism is not
+ * yet supported here. */
+static const char *
+find_gpg_agent_socket(apr_pool_t *result_pool, apr_pool_t *scratch_pool)
 {
-  char *buffer;
   char *gpg_agent_info = NULL;
   char *gnupghome = NULL;
   const char *socket_name = NULL;
-  const char *request = NULL;
-  const char *p = NULL;
-  char *ep = NULL;
-  int sd;
 
-  *new_sd = -1;
-
-  /* This implements the method of finding the socket as described in
-   * the gpg-agent man page under the --use-standard-socket option.
-   * The manage page says the standard socket is "named 'S.gpg-agent' located
-   * in the home directory."  GPG's home directory is either the directory
-   * specified by $GNUPGHOME or ~/.gnupg. */
-  gpg_agent_info = getenv("GPG_AGENT_INFO");
-  if (gpg_agent_info != NULL)
+  if ((gpg_agent_info = getenv("GPG_AGENT_INFO")) != NULL)
     {
       apr_array_header_t *socket_details;
 
@@ -256,25 +260,77 @@ find_running_gpg_agent(int *new_sd, apr_pool_t *pool)
        * The path to the socket, the pid of the gpg-agent process and
        * finally the version of the protocol the agent talks. */
       socket_details = svn_cstring_split(gpg_agent_info, ":", TRUE,
-                                         pool);
+                                         scratch_pool);
       socket_name = APR_ARRAY_IDX(socket_details, 0, const char *);
     }
   else if ((gnupghome = getenv("GNUPGHOME")) != NULL)
     {
-      const char *homedir = svn_dirent_canonicalize(gnupghome, pool);
-      socket_name = svn_dirent_join(homedir, "S.gpg-agent", pool);
+      const char *homedir = svn_dirent_canonicalize(gnupghome, scratch_pool);
+      socket_name = svn_dirent_join(homedir, "S.gpg-agent", scratch_pool);
     }
   else
     {
-      const char *homedir = svn_user_get_homedir(pool);
+      int i = 0;
+      const char *maybe_socket[] = {NULL, NULL, NULL, NULL};
+      const char *homedir;
 
-      if (!homedir)
-        return SVN_NO_ERROR;
+#ifdef APR_HAS_USER
+      apr_uid_t uid;
+      apr_gid_t gid;
 
-      homedir = svn_dirent_canonicalize(homedir, pool);
-      socket_name = svn_dirent_join_many(pool, homedir, ".gnupg",
-                                         "S.gpg-agent", SVN_VA_NULL);
+      if (apr_uid_current(&uid, &gid, scratch_pool) == APR_SUCCESS)
+        {
+          const char *uidbuf = apr_psprintf(scratch_pool, "%lu",
+                                            (unsigned long)uid);
+          maybe_socket[i++] = svn_dirent_join_many(scratch_pool, "/run/user",
+                                                   uidbuf, "gnupg",
+                                                   "S.gpg-agent",
+                                                   SVN_VA_NULL);
+          maybe_socket[i++] = svn_dirent_join_many(scratch_pool,
+                                                   "/var/run/user",
+                                                   uidbuf, "gnupg",
+                                                   "S.gpg-agent",
+                                                   SVN_VA_NULL);
+        }
+#endif
+
+      homedir = svn_user_get_homedir(scratch_pool);
+      if (homedir)
+        maybe_socket[i++] = svn_dirent_join_many(scratch_pool, homedir,
+                                                 ".gnupg", "S.gpg-agent",
+                                                 SVN_VA_NULL);
+
+      for (i = 0; !socket_name && maybe_socket[i]; i++)
+        {
+          apr_finfo_t finfo;
+          svn_error_t *err = svn_io_stat(&finfo, maybe_socket[i],
+                                         APR_FINFO_TYPE, scratch_pool);
+          if (!err && finfo.filetype == APR_SOCK)
+            socket_name = maybe_socket[i];
+          svn_error_clear(err);
+        }
     }
+
+  if (socket_name)
+    socket_name = apr_pstrdup(result_pool, socket_name);
+
+  return socket_name;
+}
+
+/* Locate a running GPG Agent, and return an open file descriptor
+ * for communication with the agent in *NEW_SD. If no running agent
+ * can be found, set *NEW_SD to -1. */
+static svn_error_t *
+find_running_gpg_agent(int *new_sd, apr_pool_t *pool)
+{
+  char *buffer;
+  const char *socket_name = find_gpg_agent_socket(pool, pool);
+  const char *request = NULL;
+  const char *p = NULL;
+  char *ep = NULL;
+  int sd;
+
+  *new_sd = -1;
 
   if (socket_name != NULL)
     {
