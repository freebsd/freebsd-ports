--- ./src/client/UniqueIdStore.cpp.orig	Sat Dec  4 13:14:34 2004
+++ ./src/client/UniqueIdStore.cpp	Tue Jan 25 19:34:21 2005
@@ -23,7 +23,7 @@
 #include <common/Logger.h>
 #include <coms/NetInterface.h>
 #include <XML/XMLFile.h>
-#include <SDL/SDL_net.h>
+#include <SDL11/SDL_net.h>
 #include <stdlib.h>
 
 UniqueIdStore::UniqueIdStore()
