--- ros/inc/LDOM_OSStream.hxx.orig	2007-10-09 16:04:22.000000000 +0200
+++ ros/inc/LDOM_OSStream.hxx	2008-09-30 22:43:53.000000000 +0200
@@ -25,12 +25,12 @@
 //          and current element of sequence,
 //          also it has methods for the sequence management.
 
-#include <Standard_OStream.hxx>
-#include <Standard_Boolean.hxx>
-
 #include <stdlib.h>
 #include <stdio.h> /* EOF */
 
+#include <Standard_OStream.hxx>
+#include <Standard_Boolean.hxx>
+
 class LDOM_StringElem; // defined in cxx file
 
 class LDOM_SBuffer : public streambuf
