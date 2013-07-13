--- subversion/libsvn_subr/gpg_agent.c	2013/07/08 14:27:14	1500761
+++ subversion/libsvn_subr/gpg_agent.c	2013/07/08 14:29:04	1500762
@@ -156,42 +156,28 @@
   return (strncmp(buf, "OK", 2) == 0);
 }
 
-/* Implementation of svn_auth__password_get_t that retrieves the password
-   from gpg-agent */
+
+/* Locate a running GPG Agent, and return an open file descriptor
+ * for communication with the agent in *NEW_SD. If no running agent
+ * can be found, set *NEW_SD to -1. */
 static svn_error_t *
-password_get_gpg_agent(svn_boolean_t *done,
-                       const char **password,
-                       apr_hash_t *creds,
-                       const char *realmstring,
-                       const char *username,
-                       apr_hash_t *parameters,
-                       svn_boolean_t non_interactive,
-                       apr_pool_t *pool)
+find_running_gpg_agent(int *new_sd, apr_pool_t *pool)
 {
-  int sd;
+  char *buffer;
   char *gpg_agent_info = NULL;
+  const char *socket_name = NULL;
+  const char *request = NULL;
   const char *p = NULL;
   char *ep = NULL;
-  char *buffer;
-
-  apr_array_header_t *socket_details;
-  const char *request = NULL;
-  const char *cache_id = NULL;
-  struct sockaddr_un addr;
-  const char *tty_name;
-  const char *tty_type;
-  const char *lc_ctype;
-  const char *display;
-  const char *socket_name = NULL;
-  svn_checksum_t *digest = NULL;
-  char *password_prompt;
-  char *realm_prompt;
+  int sd;
 
-  *done = FALSE;
+  *new_sd = -1;
 
   gpg_agent_info = getenv("GPG_AGENT_INFO");
   if (gpg_agent_info != NULL)
     {
+      apr_array_header_t *socket_details;
+
       socket_details = svn_cstring_split(gpg_agent_info, ":", TRUE,
                                          pool);
       socket_name = APR_ARRAY_IDX(socket_details, 0, const char *);
@@ -201,6 +187,8 @@
 
   if (socket_name != NULL)
     {
+      struct sockaddr_un addr;
+
       addr.sun_family = AF_UNIX;
       strncpy(addr.sun_path, socket_name, sizeof(addr.sun_path) - 1);
       addr.sun_path[sizeof(addr.sun_path) - 1] = '\0';
@@ -273,6 +261,44 @@
       return SVN_NO_ERROR;
     }
 
+  *new_sd = sd;
+  return SVN_NO_ERROR;
+}
+
+/* Implementation of svn_auth__password_get_t that retrieves the password
+   from gpg-agent */
+static svn_error_t *
+password_get_gpg_agent(svn_boolean_t *done,
+                       const char **password,
+                       apr_hash_t *creds,
+                       const char *realmstring,
+                       const char *username,
+                       apr_hash_t *parameters,
+                       svn_boolean_t non_interactive,
+                       apr_pool_t *pool)
+{
+  int sd;
+  const char *p = NULL;
+  char *ep = NULL;
+  char *buffer;
+  const char *request = NULL;
+  const char *cache_id = NULL;
+  const char *tty_name;
+  const char *tty_type;
+  const char *lc_ctype;
+  const char *display;
+  svn_checksum_t *digest = NULL;
+  char *password_prompt;
+  char *realm_prompt;
+
+  *done = FALSE;
+
+  SVN_ERR(find_running_gpg_agent(&sd, pool));
+  if (sd == -1)
+    return SVN_NO_ERROR;
+
+  buffer = apr_palloc(pool, BUFFER_SIZE);
+
   /* Send TTY_NAME to the gpg-agent daemon. */
   tty_name = getenv("GPG_TTY");
   if (tty_name != NULL)
@@ -388,8 +414,8 @@
    password in GPG Agent if that's how this particular integration
    worked.  But it isn't.  GPG Agent stores the password provided by
    the user via the pinentry program immediately upon its provision
-   (and regardless of its accuracy as passwords go), so there's
-   nothing really to do here.  */
+   (and regardless of its accuracy as passwords go), so we just need
+   to check if a usable GPG Agent exists. */
 static svn_error_t *
 password_set_gpg_agent(svn_boolean_t *done,
                        apr_hash_t *creds,
@@ -400,7 +426,21 @@
                        svn_boolean_t non_interactive,
                        apr_pool_t *pool)
 {
-  *done = TRUE;
+  int sd;
+  const char *tty_name;
+
+  *done = FALSE;
+
+  SVN_ERR(find_running_gpg_agent(&sd, pool));
+  if (sd == -1)
+    return SVN_NO_ERROR;
+
+  close(sd);
+
+  /* Also ensure that GPG_TTY is set in the evironment.
+   * If it isn't set the user won't be prompted by the agent. */
+  tty_name = getenv("GPG_TTY");
+  *done = (tty_name != NULL);
 
   return SVN_NO_ERROR;
 }
