--- src/protocol.h.orig	Wed Aug 20 19:09:09 2003
+++ src/protocol.h	Wed Aug 20 19:09:19 2003
@@ -25,7 +25,7 @@
 #ifdef WIN32
 typedef std::basic_string<char> ug_string;
 #else
-typedef basic_string<char> ug_string;
+typedef std::basic_string<char> ug_string;
 #endif
 
 class ug_bytes;
