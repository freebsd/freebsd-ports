--- example2.cpp.orig	Sat Oct  5 12:37:42 2002
+++ example2.cpp	Sat Oct  5 12:38:06 2002
@@ -181,7 +181,7 @@
 
 /**************************************** main() ********************/
 
-void main(int argc, char* argv[])
+int main(int argc, char* argv[])
 {
   /****************************************/
   /*   Initialize GLUT and create window  */
@@ -244,4 +244,5 @@
   GLUI_Master.set_glutIdleFunc( myGlutIdle );
 
   glutMainLoop();
+  return 0;
 }
