--- cmn/game.h.dist	Sat Mar 22 20:44:32 2003
+++ cmn/game.h	Sat Oct 25 21:40:54 2003
@@ -35,7 +35,8 @@
 extern "C" {
 #include <time.h>
 }
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include "utils.h"
 #include "ui.h"
 #include "world.h"
