--- korganizer/plugins/holidays/parseholiday.y	Wed Jan  9 14:57:53 2002
+++ korganizer/plugins/holidays/parseholiday.y.new	Mon Jun  3 05:53:59 2002
@@ -29,7 +29,7 @@
 #include <sys/stat.h>
 #include <string.h>
 
-#ifdef HAVE_MALLOC_H
+#if !defined(HAVE_MALLOC_H) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
