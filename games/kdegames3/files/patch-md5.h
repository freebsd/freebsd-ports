--- kpat/freecell-solver/md5.h	Thu Apr  5 14:50:56 2001
+++ kpat/freecell-solver/md5.h.new	Sat Jun  1 04:17:45 2002
@@ -13,7 +13,7 @@
 typedef unsigned __int32 u_int32_t;
 #elif defined(__osf__)
 typedef unsigned int u_int32_t;
-#elif !defined(__linux__) && !defined(__NetBSD__)
+#elif !defined(__linux__) && !defined(__NetBSD__) && !defined(__FreeBSD__)
 typedef uint32_t u_int32_t;
 #endif  
 
