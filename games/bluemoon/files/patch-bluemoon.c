--- ./bluemoon.c.orig	2010-10-19 07:59:18.000000000 +0200
+++ ./bluemoon.c	2013-12-21 14:10:23.000000000 +0100
@@ -376,7 +376,7 @@
     refresh();
 }
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     (void) signal(SIGINT, die);
     initscr();
