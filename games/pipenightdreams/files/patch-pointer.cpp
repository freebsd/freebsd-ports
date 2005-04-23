--- src/pointer.cpp.orig	Sat Jan  1 14:44:34 2005
+++ src/pointer.cpp	Sat Jan  1 14:44:44 2005
@@ -17,7 +17,7 @@
 
 #include "pointer.h"
 
-Pointer::Pointer(int row=0, int column=0){
+Pointer::Pointer(int row, int column){
   this->row=row;
   this->column=column;
   this->moved_flag=true;
