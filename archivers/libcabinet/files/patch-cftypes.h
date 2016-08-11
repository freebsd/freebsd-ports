--- cftypes.h.orig	1999-10-24 06:13:29 UTC
+++ cftypes.h
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
