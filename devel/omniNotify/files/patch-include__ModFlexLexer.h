--- ./include/ModFlexLexer.h.orig	2003-10-23 06:39:11.000000000 +0200
+++ ./include/ModFlexLexer.h	2013-09-12 19:36:38.753063172 +0200
@@ -88,7 +88,8 @@
 // Never included before - need to define base class.
 #define __FLEX_LEXER_H
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 extern "C++" {
 
