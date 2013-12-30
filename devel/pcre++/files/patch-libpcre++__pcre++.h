--- libpcre++/pcre++.h.orig
+++ libpcre++/pcre++.h
@@ -47,11 +47,11 @@
 #include <map>
 #include <stdexcept>
 #include <iostream>
+#include <clocale>
 
 
 extern "C" {
   #include <pcre.h>
-  #include <locale.h>
 }
 
 namespace pcrepp {
