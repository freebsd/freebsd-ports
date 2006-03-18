--- sysdeputil.c.orig	Mon May 23 16:34:23 2005
+++ sysdeputil.c	Mon Jan 30 20:17:40 2006
@@ -6,6 +6,10 @@
  *
  * Highly system dependent utilities - e.g. authentication, capabilities.
  */
+/* Modifications by Joe R. Doupnik, jrd@cc.usu.edu, marked as JRD, for
+PAM support on recent FreeBSD systems. Does wtmp entries for last_log. 
+Most recently tested on FBSD v6.0
+*/
 
 #include "sysdeputil.h"
 #include "str.h"
@@ -34,6 +38,9 @@
 /* For FreeBSD */
 #include <sys/param.h>
 #include <sys/uio.h>
+#include <stdio.h>  /* JRD */
+#include <syslog.h> /* JRD */
+#include <utmp.h>   /* JRD */
 
 /* Configuration.. here are the possibilities */
 #undef VSF_SYSDEP_HAVE_CAPABILITIES
@@ -302,15 +309,21 @@
     s_pamh = 0;
     return 0;
   }
-#ifdef PAM_RHOST
-  retval = pam_set_item(s_pamh, PAM_RHOST, str_getbuf(p_remote_host));
+
+/*was JRD  #ifdef PAM_RHOST */
+  {
+  char buf[UT_HOSTSIZE];	/* restrict to normal system buf size */
+  snprintf(buf, sizeof(buf), "%s", str_getbuf(p_remote_host));
+  retval = pam_set_item(s_pamh, PAM_RHOST, buf);
+   }
+/*was JRD  retval = pam_set_item(s_pamh, PAM_RHOST, str_getbuf(p_remote_host)); */
   if (retval != PAM_SUCCESS)
   {
     (void) pam_end(s_pamh, 0);
     s_pamh = 0;
     return 0;
   }
-#endif
+/*was JRD  #endif */
   retval = pam_authenticate(s_pamh, 0);
   if (retval != PAM_SUCCESS)
   {
@@ -341,6 +354,14 @@
   }
   /* Must do this BEFORE opening a session for pam_limits to count us */
   vsf_insert_uwtmp(p_user_str, p_remote_host);
+/* JRD Tell PAM our "PAM_TTY" */
+        {
+        char ttyline[UT_LINESIZE];
+        (void)snprintf(ttyline, sizeof(ttyline), "ftp%d", getpid());
+        pam_set_item(s_pamh, PAM_TTY, ttyline);
+        }
+/* JRD end */
+
   retval = pam_open_session(s_pamh, 0);
   if (retval != PAM_SUCCESS)
   {
