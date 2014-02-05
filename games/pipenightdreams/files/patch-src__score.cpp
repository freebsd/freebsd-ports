--- ./src/score.cpp.orig	2002-01-17 20:56:42.000000000 +0100
+++ ./src/score.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -18,7 +18,7 @@
 #include "score.h"
 #include <math.h>
 
-Score::Score(int value=0){
+Score::Score(int value){
   this->value=value;
   delta=0;
   changed=true;
