--- src/dos/cdrom.h.orig	Mon Oct 25 21:57:27 2004
+++ src/dos/cdrom.h	Mon Oct 25 21:59:27 2004
@@ -4,8 +4,9 @@
 
 #define MAX_ASPI_CDROM	5
 
-#include <string.h>
+#include <string>
 #include <iostream>
+#include <fstream>
 #include <vector>
 #include "dosbox.h"
 #include "mem.h"
