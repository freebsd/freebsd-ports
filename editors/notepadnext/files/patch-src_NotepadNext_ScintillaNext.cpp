--- src/NotepadNext/ScintillaNext.cpp.orig	2022-05-26 23:25:10 UTC
+++ src/NotepadNext/ScintillaNext.cpp
@@ -20,7 +20,7 @@
 #include "ScintillaNext.h"
 #include "ScintillaCommenter.h"
 
-#include "uchardet.h"
+#include <uchardet.h>
 #include <cinttypes>
 
 #include <QDir>
