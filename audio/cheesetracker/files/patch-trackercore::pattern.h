--- trackercore/pattern.h.orig	Wed May  9 22:43:05 2001
+++ trackercore/pattern.h	Fri Dec 27 21:14:20 2002
@@ -18,11 +18,14 @@
 #ifndef PATTERN_H
 #define PATTERN_H
 
+#include <iostream>
 #include <map>
 #include <vector>
 
 #include "note.h"
 #include "mutex_lock.h"
+
+using namespace std;
 
 #define PATTERN_WIDTH 64
 #define MIN_PATTERN_LENGTH 32
