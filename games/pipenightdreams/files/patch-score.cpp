--- src/score.cpp.orig	Sat Jan  1 14:44:00 2005
+++ src/score.cpp	Sat Jan  1 14:44:07 2005
@@ -18,7 +18,7 @@
 #include "score.h"
 #include <math.h>
 
-Score::Score(int value=0){
+Score::Score(int value){
   this->value=value;
   delta=0;
   changed=true;
