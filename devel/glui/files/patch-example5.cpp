--- example5.cpp.orig	Sat Oct  5 12:39:00 2002
+++ example5.cpp	Sat Oct  5 12:39:35 2002
@@ -310,7 +310,7 @@
 
 /**************************************** main() ********************/
 
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
   /****************************************/
   /*   Initialize GLUT and create window  */
@@ -478,5 +478,6 @@
   /**** Regular GLUT main loop ****/
   
   glutMainLoop();
+  return 0;
 }
 
