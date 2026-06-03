--- src/ScintillaNext.cpp.orig	2026-04-27 22:33:55 UTC
+++ src/ScintillaNext.cpp
@@ -22,7 +22,7 @@
 #include "ScintillaCommenter.h"
 
 #include "ByteArrayUtils.h"
-#include "uchardet.h"
+#include <uchardet.h>
 #include <cinttypes>
 
 #include <QDir>
