diff -u -x _darcs -ur _darcs/current/sysdef.h ./sysdef.h
--- _darcs/current/sysdef.h	Tue Jun 14 20:14:40 2005
+++ ./sysdef.h	Sun Aug 21 02:47:40 2005
@@ -26,3 +26,7 @@
 	gid_t		fi_gid;
 	mode_t		fi_mode;
 };
+
+#ifndef LOGIN_NAME_MAX
+#define LOGIN_NAME_MAX MAXLOGNAME
+#endif
