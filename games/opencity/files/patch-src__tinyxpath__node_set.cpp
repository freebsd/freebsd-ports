--- src/tinyxpath/node_set.cpp.orig	2011-07-03 20:36:33.000000000 +0400
+++ src/tinyxpath/node_set.cpp	2014-03-28 20:44:24.828732644 +0400
@@ -23,9 +23,7 @@
 */
 
 #include "node_set.h"
-#ifdef HAVE_STDINT_H
 	#include "stdint.h"			// for intptr_t (32/64 bits void* pointer compatibility)
-#endif
 
 namespace TinyXPath
 {
