--- game/soccergame.cpp.orig	2013-09-13 20:44:15.075226353 +0400
+++ game/soccergame.cpp	2013-09-13 20:45:02.462227890 +0400
@@ -1,3 +1,5 @@
+#include <unistd.h> // for chdir
+
 #include "soccergame.h"
 #include "stadium.h"
 #include "menuchapping.h"
