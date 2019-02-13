--- src/HexEditor.h.orig	2017-12-31 02:15:18 UTC
+++ src/HexEditor.h
@@ -25,7 +25,8 @@
 #ifndef _wxHexEditor_h_
 #define _wxHexEditor_h_
 
-#include "../mhash/include/mhash.h"
+typedef bool _Bool;
+#include <mhash.h>
 
 #include <wx/ffile.h>
 #include <wx/clipbrd.h>
