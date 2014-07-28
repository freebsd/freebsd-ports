--- lbreakout/game.cpp	2000/10/20 07:02:55	1.1
+++ lbreakout/game.cpp	2000/10/20 07:03:35
@@ -15,6 +15,7 @@
  *                                                                         *
  ***************************************************************************/
 
+#include <sys/types.h>
 #include <sys/timeb.h>
 #include <stdlib.h>
 #include <string.h>
@@ -22,6 +23,10 @@
 #include "breakout.h"
 #include "menumanager.h"
 #include "level.h"
+
+extern "C" {
+	int ftime(struct timeb *tp);
+};
 
 #ifdef SOUND
 extern SndSrv sndsrv;
