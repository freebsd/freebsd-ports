--- example4.cpp.orig	Sat Oct  5 12:38:51 2002
+++ example4.cpp	Sat Oct  5 12:39:16 2002
@@ -253,7 +253,7 @@
 
 /**************************************** main() ********************/
 
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
   /****************************************/
   /*   Initialize GLUT and create window  */
@@ -371,5 +371,6 @@
   /**** Regular GLUT main loop ****/
   
   glutMainLoop();
+  return 0;
 }
 
