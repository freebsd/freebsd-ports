--- kaptain/tools.cpp.orig	Wed Aug 14 06:17:39 2002
+++ kaptain/tools.cpp	Fri Dec 20 18:53:13 2002
@@ -1,8 +1,10 @@
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/types.h>
 #include <regex.h>
 #include "tools.h"
 
+using namespace std;
 
 Error::Error()
 {
