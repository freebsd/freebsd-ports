--- cftypes.h.orig	Tue Aug 19 18:17:55 2003
+++ cftypes.h	Tue Aug 19 18:18:54 2003
@@ -18,6 +18,9 @@
 
 #include <fstream.h>
 
+using std::istream;
+using std::ostream;
+
 typedef unsigned char byte;
 typedef unsigned short int word;
 typedef unsigned long int dword;
