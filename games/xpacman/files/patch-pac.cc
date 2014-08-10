--- pac.cc.orig	1995-07-20 16:59:35.000000000 +0400
+++ pac.cc	2014-08-09 11:48:00.762643451 +0400
@@ -82,7 +82,7 @@
 UserInterface::setlpCmdLine(lpCmdLine);
 UserInterface::setnCmdShow(nCmdShow);
 #else
-main(int argc,char **argv) {
+int main(int argc,char **argv) {
 Argument(argc, argv); 		// storing the command line arguments
 #endif
 
