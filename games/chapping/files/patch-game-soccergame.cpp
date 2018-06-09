--- game/soccergame.cpp.orig	2008-05-06 17:38:43 UTC
+++ game/soccergame.cpp
@@ -1,3 +1,5 @@
+#include <unistd.h> // for chdir
+
 #include "soccergame.h"
 #include "stadium.h"
 #include "menuchapping.h"
