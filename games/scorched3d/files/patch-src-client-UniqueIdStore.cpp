--- ./src/client/UniqueIdStore.cpp.orig	Sat Aug  6 13:57:39 2005
+++ ./src/client/UniqueIdStore.cpp	Tue Aug  9 23:21:17 2005
@@ -24,7 +24,7 @@
 #include <common/OptionsDisplay.h>
 #include <coms/NetInterface.h>
 #include <XML/XMLFile.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <stdlib.h>
 
 UniqueIdStore::UniqueIdStore()
