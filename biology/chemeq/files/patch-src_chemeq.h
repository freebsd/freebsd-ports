
$FreeBSD$

--- src/chemeq.h.orig	Sat Mar  8 21:48:53 2003
+++ src/chemeq.h	Sat Mar  8 21:50:34 2003
@@ -2,10 +2,12 @@
 #define CHEMEQ_H
 
 #include <string.h>
-#include <stdiostream.h>
+#include <iostream>
 #include <vector>
 #include <string>
 #include <map>
+
+using namespace std;
 
 typedef struct {
   int Zed;
