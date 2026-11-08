--- src/language.cpp.orig	2026-03-10 11:47:14 UTC
+++ src/language.cpp
@@ -46,9 +46,9 @@
 #include "pluralforms/pl_evaluate.h"
 
 #ifdef HAVE_CLD2
-    #ifdef HAVE_CLD2_PUBLIC_COMPACT_LANG_DET_H
-        #include <cld2/public/compact_lang_det.h>
-        #include <cld2/public/encodings.h>
+    #ifdef HAVE_CLD_PUBLIC_COMPACT_LANG_DET_H
+        #include <cld/public/compact_lang_det.h>
+        #include <cld/public/encodings.h>
     #else
         #include "public/compact_lang_det.h"
         #include "public/encodings.h"
