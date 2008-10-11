--- rts/Game/GameServer.cpp.orig	2008-10-05 04:39:05.000000000 +0400
+++ rts/Game/GameServer.cpp	2008-10-09 21:37:00.000000000 +0400
@@ -15,7 +15,7 @@
 #if defined DEDICATED || defined DEBUG
 #include <iostream>
 #endif
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "mmgr.h"
 
