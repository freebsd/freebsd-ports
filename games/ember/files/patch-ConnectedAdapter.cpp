--- src/services/server/ConnectedAdapter.cpp.orig	2009-04-05 11:57:35.000000000 +0200
+++ src/services/server/ConnectedAdapter.cpp	2009-04-05 11:57:43.000000000 +0200
@@ -25,6 +25,7 @@
 #endif
 
 #include "ConnectedAdapter.h"
+#include <Atlas/Objects/Operation.h>
 #include <Eris/Connection.h>
 #include <Eris/Account.h>
 #include <Eris/Lobby.h>
