--- mysql-gui-common/library_grt/source/myx_grt_private.c.orig	Sat Nov  6 20:21:40 2004
+++ mysql-gui-common/library_grt/source/myx_grt_private.c	Sat Nov  6 20:22:02 2004
@@ -47,8 +47,10 @@
 int myx_grt_printf(MYX_GRT *grt, const char *fmt, ...)
 {
   va_list args;
+  char *tmp;
+
   va_start(args, fmt);
-  char *tmp= g_strdup_vprintf(fmt, args);
+  tmp= g_strdup_vprintf(fmt, args);
   va_end(args);
   
   MYX_PRINT(grt, tmp);
