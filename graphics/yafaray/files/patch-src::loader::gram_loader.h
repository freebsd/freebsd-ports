--- src/loader/gram_loader.h.orig	Thu Sep 30 14:48:47 2004
+++ src/loader/gram_loader.h	Thu Sep 30 14:49:18 2004
@@ -22,6 +22,10 @@
 #ifndef __GRAML_H
 #define __GRAML_H
 
+#include <iostream>
+
+using namespace std;
+
 #include "gram_lex.h"
 
 struct sym_t
