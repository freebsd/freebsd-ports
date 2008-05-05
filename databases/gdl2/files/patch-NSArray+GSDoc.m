--- Tools/NSArray+GSDoc.m.orig	2005-08-17 10:07:57.000000000 +0200
+++ Tools/NSArray+GSDoc.m	2008-05-03 09:10:55.000000000 +0200
@@ -36,6 +36,7 @@
 
 #ifdef GNUSTEP
 #include <Foundation/NSAutoreleasePool.h>
+#include <Foundation/NSString.h>
 #else
 #include <Foundation/Foundation.h>
 #endif
