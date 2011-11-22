--- libdjvu/GSmartPointer.h.orig	2011-03-06 12:43:17.000000000 -0500
+++ libdjvu/GSmartPointer.h	2011-11-22 09:16:50.000000000 -0500
@@ -94,6 +94,7 @@
 #pragma warning( disable : 4243 )
 #endif
 
+#include <stddef.h>
 #include "DjVuGlobal.h"
 #include "atomic.h"
 
