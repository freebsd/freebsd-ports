http://qa.openoffice.org/issues/show_bug.cgi?id=27033
--- ../hwpfilter/source/hwpreader.hxx~	Wed Oct 15 23:37:24 2003
+++ ../hwpfilter/source/hwpreader.hxx	Sun Mar 28 22:46:18 2004
@@ -68,7 +68,9 @@
 #include <string.h>
 #ifdef WIN32
 #include <malloc.h>
-#else
+#endif
+
+#if !defined(FREEBSD)
 #include <alloca.h>
 #endif
 
