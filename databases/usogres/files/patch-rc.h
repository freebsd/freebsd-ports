--- src/rc.h.orig	Wed Aug 20 19:04:19 2003
+++ src/rc.h	Wed Aug 20 19:07:33 2003
@@ -29,7 +29,7 @@
 #ifdef WIN32
 typedef std::basic_string<char> string;
 #else
-typedef basic_string<char> string;
+typedef std::basic_string<char> string;
 #endif
 
 class UsogresRC {
