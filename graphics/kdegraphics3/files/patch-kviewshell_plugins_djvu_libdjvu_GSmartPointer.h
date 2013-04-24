The explicit reference to std-namespace seems necessary
for compiling with gcc48.

	-mi

--- kviewshell/plugins/djvu/libdjvu/GSmartPointer.h	2005-09-10 04:19:20.000000000 -0400
+++ kviewshell/plugins/djvu/libdjvu/GSmartPointer.h	2013-04-24 17:27:13.000000000 -0400
@@ -107,5 +107,5 @@
 #endif
 
-
+using namespace std;
 
 /* What is this innovation ? 
