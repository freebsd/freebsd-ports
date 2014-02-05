--- ./src/pipe.cpp.orig	2002-01-21 05:08:13.000000000 +0100
+++ ./src/pipe.cpp	2014-02-01 23:41:06.000000000 +0100
@@ -43,11 +43,11 @@
   return !(full_level>0) && !fixed;
 }
 
-void Pipe::setFixed(bool flag=true){
+void Pipe::setFixed(bool flag){
   fixed=flag;
 }
 
-void Pipe::setBonus(Bonus bonus=NormalBonus){
+void Pipe::setBonus(Bonus bonus){
   this->bonus=bonus;
 }
 
