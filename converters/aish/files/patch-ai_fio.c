--- ./ai_fio.c.orig	1994-10-14 08:02:38.000000000 +0100
+++ ./ai_fio.c	2012-08-24 11:52:22.029913407 +0200
@@ -226,6 +226,7 @@
 int	noerrflag= 0;
 #endif
 
+void
 Mputchar( ch )
 char	ch;
 {
@@ -236,6 +237,7 @@
 	putchar( ch );
 }
 
+void
 Merrch( ch )
 char	ch;
 {
