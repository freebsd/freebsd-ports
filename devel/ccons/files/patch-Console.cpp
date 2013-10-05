--- ./Console.cpp.orig	2013-09-18 15:56:23.000000000 -0300
+++ ./Console.cpp	2013-09-18 15:56:32.000000000 -0300
@@ -12,6 +12,7 @@
 
 #include <errno.h>
 #include <ctype.h>
+#include <unistd.h>
 
 #include <iostream>
 #include <map>
