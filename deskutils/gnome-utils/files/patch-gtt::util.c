
$FreeBSD$

--- gtt/util.c	2001/10/10 09:55:09	1.1
+++ gtt/util.c	2001/10/10 09:57:22
@@ -32,7 +32,9 @@
 #include <gnome.h>
 
 /* hack alert --xxx fixme -- we need to configure.in for have_langinfo */
+#if (defined __FreeBSD__) && (__FreeBSD_version > 500000)
 #define HAVE_LANGINFO_D_FMT
+#endif
 #ifdef HAVE_LANGINFO_D_FMT
 #include <langinfo.h>
 #endif
