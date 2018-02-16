--- src/recorder.cpp.orig	2013-10-03 09:22:51 UTC
+++ src/recorder.cpp
@@ -20,6 +20,7 @@
 #include <fx.h>
 #include <Scintilla.h>
 
+#include "compat.h"
 #include "macro.h"
 
 #include "intl.h"
@@ -288,7 +289,7 @@ void MacroRecorder::translate(TranslateFunc callback, 
         break;
       }
       case SCI_SELECTALL: {
-        text=_LUAMOD_".select(0,"_LUAMOD_".nchars())";
+        text=_LUAMOD_".select(0," _LUAMOD_ ".nchars())";
         break;
       }
 
