--- cftypes.h.orig	1999-10-24 02:13:29.000000000 -0400
+++ cftypes.h	2014-02-21 15:42:11.491293648 -0500
@@ -16,7 +16,10 @@
 #ifndef __CFTYPES_H__
 #define __CFTYPES_H__
 
-#include <fstream.h>
+#include <fstream>
+
+using std::istream;
+using std::ostream;
 
 typedef unsigned char byte;
 typedef unsigned short int word;
