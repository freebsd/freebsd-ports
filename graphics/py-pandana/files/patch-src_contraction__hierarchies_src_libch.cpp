--- src/contraction_hierarchies/src/libch.cpp.orig	2021-03-15 17:17:09 UTC
+++ src/contraction_hierarchies/src/libch.cpp
@@ -20,7 +20,7 @@ or see http://www.gnu.org/licenses/agpl.txt.
 
 #include "libch.h"
 #include "POIIndex/POIIndex.h"
-#ifdef _OPENMP
+#if defined(_OPENMP) && (defined(__amd64__) || defined(__i386__))
 #include "Util/HyperThreading.h"
 #endif
 namespace CH {
