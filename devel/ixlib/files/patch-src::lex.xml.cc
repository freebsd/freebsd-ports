--- src/lex.xml.cc.orig	Tue Oct 23 12:24:43 2001
+++ src/lex.xml.cc	Fri Dec  1 18:57:06 2006
@@ -24,9 +24,12 @@
 #ifdef __cplusplus
 
 #include <stdlib.h>
-#include <fstream>
+#include <iostream>
 using std::istream;
 using std::ostream;
+using std::cin;
+using std::cout;
+using std::cerr;
 #include <unistd.h>
 
 /* Use prototypes in function declarations. */
