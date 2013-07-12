--- mod_mem/mod_mem.c.orig	2009-06-15 22:34:24.000000000 +0400
+++ mod_mem/mod_mem.c	2009-11-06 06:28:55.000000000 +0300
@@ -128,7 +128,7 @@
     get_system_info( &info );
     return B_PAGE_SIZE * ( info.max_pages - info.used_pages );
 
-#elif !defined(TARGET_MAC)
+#elif !defined(TARGET_MAC) && !defined(TARGET_BSD)
     /* Linux and other Unix (?) */
     struct sysinfo meminf;
     int fv;
@@ -166,7 +166,7 @@
     get_system_info( &info );
     return  B_PAGE_SIZE * ( info.max_pages );
 
-#elif !defined(TARGET_MAC)
+#elif !defined(TARGET_MAC) && !defined(TARGET_BSD)
     /* Linux and other Unix (?) */
     struct sysinfo meminf;
     int fv;
