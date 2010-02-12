--- src/MEDSPLITTER/MEDSPLITTER_SCOTCHGraph.cxx.orig	2009-12-17 13:53:26.000000000 +0600
+++ src/MEDSPLITTER/MEDSPLITTER_SCOTCHGraph.cxx	2009-12-17 13:53:59.000000000 +0600
@@ -19,7 +19,7 @@
 #include <cstdio>
 extern "C" {
 #define restrict
-#include "bin/scotch.h"
+#include "scotch.h"
 }
 #include "MEDSPLITTER_Graph.hxx"
 #include "MEDSPLITTER_SCOTCHGraph.hxx"
