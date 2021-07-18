--- src/lib/logic/wordengine.cpp.orig	2021-06-30 10:20:03 UTC
+++ src/lib/logic/wordengine.cpp
@@ -31,6 +31,7 @@
 
 #include "wordengine.h"
 #include "abstractlanguageplugin.h"
+#include <clocale>
 
 namespace MaliitKeyboard {
 namespace Logic {
