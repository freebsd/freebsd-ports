--- gnats/gnatsd.c.orig	Wed Sep 22 02:18:39 1999
+++ gnats/gnatsd.c	Tue Aug 20 21:11:28 2002
@@ -24,6 +24,15 @@
 #include "query.h"
 #include "db_conf.h"
 
+#ifdef HAVE_PAM
+#include <security/pam_appl.h>
+#ifdef _OPENPAM
+#include <security/openpam.h>
+#endif
+
+static int issetuidroot;
+#endif /* HAVE_PAM */
+
 char myname[MAXHOSTNAMELEN];
 
 char *program_name;
@@ -387,9 +396,9 @@
   return found;
 }
 
-/* Get the access lever for this user. */
-int
-get_user_access (database, filename, user, passwd)
+/* Get the access level for this user using the file backend. */
+static int
+get_user_access_file (database, filename, user, passwd)
      char *database;
      char *filename;
      char *user;
@@ -489,6 +498,86 @@
   return access;
 }
 
+#ifdef HAVE_PAM
+#ifndef _OPENPAM
+int
+pam_conv (n, msg, resp, data)
+      int n;
+      const struct pam_message **msg;
+      struct pam_response **resp;
+      void *data;
+{
+
+  if (n != 1 || msg[0]->msg_style != PAM_PROMPT_ECHO_OFF)
+    return(PAM_CONV_ERR);
+  if ((*resp = malloc(sizeof(struct pam_response))) == NULL)
+    return(PAM_CONV_ERR);
+  (*resp)[0].resp = strdup((const char *)data);
+  (*resp)[0].resp_retcode = 0;
+
+  return ((*resp)[0].resp != NULL ? PAM_SUCCESS : PAM_CONV_ERR);
+}
+#endif /* _OPENPAM */
+
+/* Get the access level for this user using the PAM backend. */
+static int
+get_user_access_pam (user, passwd)
+     char *user;
+     char *passwd;
+{
+  int access;
+  pam_handle_t *pamh;
+  struct pam_conv pamc = {
+#ifdef _OPENPAM
+    &openpam_nullconv, NULL
+#else
+    &pam_conv, passwd
+#endif
+  };
+
+  access = -1;
+
+  /* PAM chain may require super-user. */
+  if (issetuidroot)
+    seteuid(0);
+
+  if (pam_start("gnatsd", user, &pamc, &pamh) == PAM_SUCCESS &&
+#ifdef _OPENPAM
+      pam_set_item(pamh, PAM_AUTHTOK, passwd) == PAM_SUCCESS &&
+#endif
+      pam_authenticate(pamh, 0) == PAM_SUCCESS)
+    {
+      access = ACCESS_EDIT;
+    }
+
+  /* Revert back to real UID. */
+  if (issetuidroot)
+    seteuid(getuid());
+
+  return access;
+}
+#endif /* HAVE_PAM */
+
+/* Get the access level for this user. */
+int
+get_user_access (database, filename, user, passwd)
+     char *database;
+     char *filename;
+     char *user;
+     char *passwd;
+{
+  int access;
+
+  access = -1;
+
+#ifdef HAVE_PAM
+  if ((access = get_user_access_pam(user, passwd)) == -1)
+#endif /* HAVE_PAM */
+  access = get_user_access_file(database, filename, user, passwd);
+
+  return access;
+}
+
 void
 start_connection ()
 {
@@ -680,6 +769,11 @@
   int optc;
   int not_inetd  = 0;
   int access, access_required;
+
+#ifdef HAVE_PAM
+  if ((issetuidroot = geteuid() == 0 && getuid() != 0))
+    seteuid(getuid());
+#endif /* HAVE_PAM */
 
   outfile = stdout;
 
