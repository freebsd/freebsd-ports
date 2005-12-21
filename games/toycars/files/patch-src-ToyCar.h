--- src/ToyCar.h.orig	Mon Dec 12 04:11:19 2005
+++ src/ToyCar.h	Mon Dec 19 11:39:10 2005
@@ -25,6 +25,11 @@
 #include "WheelSprite.h"
 #include "ScSprite.h"
 
+#include <stdio.h>
+#include <time.h>
+#include <unistd.h>
+#include <string>
+
 // ToyCar class
 
 class ToyCar : public Vehicle, public ScSprite
