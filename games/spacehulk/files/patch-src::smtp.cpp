--- src/smtp.cpp.orig	Thu Aug 21 12:03:45 2003
+++ src/smtp.cpp	Thu Aug 28 20:44:12 2003
@@ -15,6 +15,7 @@
 #include <qtimer.h>
 #include <qapplication.h>
 #include <qmessagebox.h>
+#include <ctype.h>
 
 #include <iostream>
 using namespace std;
@@ -337,9 +338,6 @@
   char *outp = out;
   char buf[4];
 
-  if (inlen < 0)
-    inlen = INT_MAX;
-  
   while (inlen >= 4 && *inp != '\0') {
     buf[0] = *inp++;
     inlen--;
