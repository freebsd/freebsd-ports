--- phatbeat.cpp.orig	Tue Jun 22 02:34:13 2004
+++ phatbeat.cpp	Tue Jun 22 02:35:53 2004
@@ -24,6 +24,9 @@
 #include "BeatCounter.h" 
 using namespace std;
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <string.h>
 #include <stdlib.h>
 using namespace std;
 #include <stdio.h>
