--- ./lexer.l.orig	2013-05-24 16:51:05.980063986 +0200
+++ ./lexer.l	2013-05-24 16:50:37.162061270 +0200
@@ -9,6 +9,7 @@
  *
  */
 
+%option noinput
 %{
 #include "stdio.h"
 #include "string.h"
