--- ui/zenoedit/recordmain.cpp.orig	2024-04-26 16:42:36 UTC
+++ ui/zenoedit/recordmain.cpp
@@ -15,6 +15,7 @@
 #include <zeno/utils/log.h>
 #include "common.h"
 #include <rapidjson/document.h>
+#include "zenoapplication.h"
 
 
 //--record true --zsg "C:\zeno\framenum.zsg" --cachePath "C:\tmp" --sframe 0 --frame 10 --sample 1 --optix 1 --path "C:\recordpath" --pixel 4500x3500 --aov 0 --needDenoise 0
