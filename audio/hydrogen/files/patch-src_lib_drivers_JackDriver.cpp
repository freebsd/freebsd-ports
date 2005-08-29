--- src/lib/drivers/JackDriver.cpp.orig	Mon Aug 29 19:29:16 2005
+++ src/lib/drivers/JackDriver.cpp	Mon Aug 29 19:29:27 2005
@@ -25,6 +25,7 @@
 #include "JackDriver.h"
 #ifdef JACK_SUPPORT
 
+#include <stdio.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include "lib/Hydrogen.h"
