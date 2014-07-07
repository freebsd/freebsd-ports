--- src/openhbci/simpleconfig.cpp.orig	2003-07-02 22:22:24.000000000 +0400
+++ src/openhbci/simpleconfig.cpp	2014-07-03 13:53:03.000000000 +0400
@@ -37,6 +37,7 @@
 #include "simpleconfig.h"
 
 #include <stdio.h>
+#include <stdlib.h> // for atoi()
 #include "parser.h"
 #include "filestream.h"
 
