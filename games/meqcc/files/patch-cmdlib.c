--- cmdlib.c.orig	Sat Jan 15 20:08:10 2005
+++ cmdlib.c	Sat Jan 15 20:03:02 2005
@@ -141,6 +141,8 @@
 ================
 */
 // MrE:
+long int tell (int);
+
 long int filelength (int handle)
 {
 	/*
