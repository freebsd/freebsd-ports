--- mod_mem/mod_mem.c.orig	2013-09-12 06:03:12.588226648 +0400
+++ mod_mem/mod_mem.c	2013-09-12 06:03:50.452231577 +0400
@@ -133,7 +133,7 @@
     get_system_info( &info );
     return B_PAGE_SIZE * ( info.max_pages - info.used_pages );
 
-#elif !defined(TARGET_MAC) && !defined(TARGET_WII)
+#elif !defined(TARGET_MAC) && !defined(TARGET_WII) && !defined(TARGET_BSD)
     /* Linux and other Unix (?) */
     struct sysinfo meminf;
     int fv;
@@ -171,7 +171,7 @@
     get_system_info( &info );
     return  B_PAGE_SIZE * ( info.max_pages );
 
-#elif !defined(TARGET_MAC) && !defined(TARGET_WII)
+#elif !defined(TARGET_MAC) && !defined(TARGET_WII) && !defined(TARGET_BSD)
     /* Linux and other Unix (?) */
     struct sysinfo meminf;
     int fv;
