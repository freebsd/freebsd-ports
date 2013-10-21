--- doc/man/ivman/Main.c++.orig	2013-10-10 14:52:11.000000000 +0200
+++ doc/man/ivman/Main.c++	2013-10-10 14:52:17.000000000 +0200
@@ -89,7 +89,7 @@
 //
 /////////////////////////////////////////////////////////////////////////////
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     SbBool	ok = TRUE;
     int		c, curArg;
