--- src/engine/timeconstraint.cpp.orig	2016-04-09 13:57:44 UTC
+++ src/engine/timeconstraint.cpp
@@ -39,6 +39,7 @@ File timeconstraint.cpp
 
 //for min max functions
 #include <algorithm>
+#include <stdlib.h>
 using namespace std;
 
 static QString trueFalse(bool x){
