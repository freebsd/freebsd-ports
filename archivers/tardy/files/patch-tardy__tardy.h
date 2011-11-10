--- ./tardy/tardy.h.orig	2011-11-10 20:05:42.000000000 +0100
+++ ./tardy/tardy.h	2011-11-10 20:06:06.000000000 +0100
@@ -38,7 +38,7 @@
 void tardy_no_directories(void);
 void tardy_no_fix_type(void);
 void tardy_now(void);
-void tardy_mtime(long when);
+void tardy_mtime(time_t when);
 void tardy_prefix(const char *);
 void tardy_remove_prefix(const char *);
 void tardy_remove_prefix(long);
