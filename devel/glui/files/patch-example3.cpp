--- example3.cpp.orig	Sat Oct  5 12:42:22 2002
+++ example3.cpp	Sat Oct  5 12:42:39 2002
@@ -263,7 +263,7 @@
 
 /**************************************** main() ********************/
 
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
   /****************************************/
   /*   Initialize GLUT and create window  */
@@ -392,5 +392,6 @@
 
   /**** Regular GLUT main loop ****/  
   glutMainLoop();
+  return 0;
 }
 
