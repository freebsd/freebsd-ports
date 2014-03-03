--- ./src/engine/timeconstraint.cpp.orig	2014-02-01 14:51:03.804739136 +0100
+++ ./src/engine/timeconstraint.cpp	2014-02-01 14:51:46.994628354 +0100
@@ -42,6 +42,7 @@
 
 //for min max functions
 #include <algorithm>
+#include <stdlib.h>
 using namespace std;
 
 static QString trueFalse(bool x){
