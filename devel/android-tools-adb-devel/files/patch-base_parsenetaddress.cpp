--- base/parsenetaddress.cpp.orig	2016-02-20 02:39:51 UTC
+++ base/parsenetaddress.cpp
@@ -16,6 +16,7 @@
 
 #include "android-base/parsenetaddress.h"
 
+#include <stdio.h> // sscanf
 #include <algorithm>
 
 #include "android-base/stringprintf.h"
