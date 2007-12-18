--- src/readmidi.cc.orig	2007-12-18 19:57:34.000000000 +0100
+++ src/readmidi.cc	2007-12-18 19:57:44.000000000 +0100
@@ -30,7 +30,8 @@
 # include "config.h"
 #endif
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <stdio.h>
 #include <errno.h>
 
