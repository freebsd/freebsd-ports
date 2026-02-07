--- ./src/pointer.cpp.orig	2002-01-17 20:56:41.000000000 +0100
+++ ./src/pointer.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -17,7 +17,7 @@
 
 #include "pointer.h"
 
-Pointer::Pointer(int row=0, int column=0){
+Pointer::Pointer(int row, int column){
   this->row=row;
   this->column=column;
   this->moved_flag=true;
