
$FreeBSD$

--- fdstream.h	2002/02/05 13:25:12	1.1
+++ fdstream.h	2002/02/05 13:36:05
@@ -26,6 +26,8 @@
 
 namespace Gnomoku
 {
+    typedef char char_type;
+
     class fdstreambuf : public std::streambuf
     {
 	int   buf_size;
