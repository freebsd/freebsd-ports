--- src/pipe.cpp.orig	Sat Jan  1 14:45:09 2005
+++ src/pipe.cpp	Sat Jan  1 14:45:19 2005
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
 
