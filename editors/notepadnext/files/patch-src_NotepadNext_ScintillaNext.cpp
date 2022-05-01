--- src/NotepadNext/ScintillaNext.cpp.orig	2022-05-01 01:18:16 UTC
+++ src/NotepadNext/ScintillaNext.cpp
@@ -17,7 +17,7 @@
  */
 
 #include "ScintillaNext.h"
-#include "uchardet.h"
+#include <uchardet.h>
 #include <cinttypes>
 
 #include <QDir>
