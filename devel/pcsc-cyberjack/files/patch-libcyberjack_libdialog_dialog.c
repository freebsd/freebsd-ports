--- libcyberjack/libdialog/dialog.c.orig	2021-11-03 13:00:16 UTC
+++ libcyberjack/libdialog/dialog.c
@@ -22,7 +22,7 @@
  *                                                                         *
  ***************************************************************************/
 
-
+#include "config.h"
 #include "Platform.h"
 #include "dialog_p.h"
 #include "network.h"
@@ -30,7 +30,11 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <pwd.h>
+#ifdef OS_FREEBSD
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 
 #include <errno.h>
 #include <string.h>
@@ -120,11 +124,19 @@ static int rsct_dialog_mk_socket() {
 
 static int rsct_dialog_mk_socket() {
   char buffer[256];
+#ifdef OS_FREEBSD
+  struct utmpx *u_tmp_p;
+#else
   struct utmp *u_tmp_p;
+#endif
   struct passwd *pw;
   int sk;
 
+#ifdef OS_FREEBSD
+  while ((u_tmp_p = getutxent()) != NULL) {
+#else
   while ((u_tmp_p = getutent()) != NULL) {
+#endif
     DEBUGPI("RSCT: ut_type=%d, ut_line=[%s]\n",
 	    u_tmp_p->ut_type,
 	    u_tmp_p->ut_line);
@@ -136,7 +148,11 @@ static int rsct_dialog_mk_socket() {
 
   if (u_tmp_p==NULL) {
     DEBUGPE("RSCT: No user logged in at XServer :0 (%s (%d))\n", strerror(errno), errno);
+#ifdef OS_FREEBSD
+    endutxent();
+#else
     endutent();
+#endif
     return -1;
   }
 
@@ -144,18 +160,31 @@ static int rsct_dialog_mk_socket() {
   if (pw==NULL) {
     DEBUGPE("RSCT: Could not get home folder for user [%s]: %s (%d)\n",
 	    u_tmp_p->ut_user, strerror(errno), errno);
+#ifdef OS_FREEBSD
+    endutxent();
+#else
     endutent();
+#endif
     return -1;
   }
 
   if (pw->pw_dir==NULL || *(pw->pw_dir)==0) {
     DEBUGPE("RSCT: User [%s] has no home folder\n", u_tmp_p->ut_user);
+#ifdef OS_FREEBSD
+    endutxent();
+#else
     endutent();
+#endif
     return -1;
   }
   strncpy(buffer, pw->pw_dir, sizeof(buffer)-1);
   strncat(buffer, "/.cyberJack_gui_sock", sizeof(buffer)-1);
+#ifdef OS_FREEBSD
+  endutxent();
+#else
   endutent();
+#endif
+
 
   sk=rsct_net_connect_by_path(buffer);
   if (sk==-1) {
