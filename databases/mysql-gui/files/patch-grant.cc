--- grant.cc.orig	Wed Apr 11 21:12:24 2001
+++ grant.cc	Mon Feb  3 03:47:34 2003
@@ -23,6 +23,7 @@
 #endif
 #include <iomanip>
 #include <string>
+#undef Success
 #include <sqlplus.hh>
 
 #define REFRESH_GRANT		1	/* Refresh grant tables */
