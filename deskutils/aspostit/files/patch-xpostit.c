--- xpostit.c.orig	1999-01-08 06:10:27.000000000 +0900
+++ xpostit.c	2012-10-24 01:06:04.000000000 +0900
@@ -32,6 +32,7 @@
 #include <X11/Xaw/SimpleMenu.h>
 #include <signal.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "xpostit.h"
 #include "version.h"
@@ -130,7 +131,7 @@
 unsigned long timer_interval;	/* auto-save interval */
 unsigned long alarm_interval;	/* alarm check interval */
 
-void main(argc, argv)
+int main(argc, argv)
 char **argv;
 int argc;
 {
