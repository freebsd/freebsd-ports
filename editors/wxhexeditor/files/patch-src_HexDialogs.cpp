--- src/HexDialogs.cpp.orig	2017-12-31 02:15:18 UTC
+++ src/HexDialogs.cpp
@@ -24,7 +24,8 @@
 #define NANINT 0xFFFFFFFFFFFFFFFFLL
 #include "HexDialogs.h"
 #include <wx/progdlg.h>
-#include "../mhash/include/mhash.h"
+typedef bool _Bool;
+#include <mhash.h>
 
 #ifdef __SSE2__
 	#include <emmintrin.h>
