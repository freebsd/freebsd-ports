--- drumgizmo/input/ossmidi.cc.orig	2018-10-06 16:29:02 UTC
+++ drumgizmo/input/ossmidi.cc
@@ -30,6 +30,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <iostream>
+#include <cstring>
 
 
 static int const NOTE_ON = 0x90;
