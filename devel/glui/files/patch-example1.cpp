--- example1.cpp.orig	Sat Oct  5 12:36:47 2002
+++ example1.cpp	Sat Oct  5 12:37:20 2002
@@ -85,7 +85,7 @@
 
 /**************************************** main() ********************/
 
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
   /****************************************/
   /*   Initialize GLUT and create window  */
@@ -136,6 +136,7 @@
   GLUI_Master.set_glutIdleFunc( myGlutIdle ); 
 
   glutMainLoop();
+  return 0;
 }
 
 
