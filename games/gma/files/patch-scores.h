--- src/scores.h.orig	Mon Apr 17 02:52:22 2000
+++ src/scores.h	Sun May 18 19:19:41 2003
@@ -22,10 +22,12 @@
 #ifndef SCORES_H
 #define SCORES_H
 
-#include <stl.h>
+#include <map>
 #include <string>
 #include "pattern.h"
 
+using std::map;
+
 class Scores
 {
 public:
