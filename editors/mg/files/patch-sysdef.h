--- sysdef.h.orig	Mon Dec 29 11:37:41 2003
+++ sysdef.h	Mon Dec 29 11:38:00 2003
@@ -23,5 +23,5 @@
 struct fileinfo {
 	mode_t          fi_mode;
 	uid_t           fi_uid;
-	gid_t short     fi_gid;
+	gid_t	fi_gid;
 };
