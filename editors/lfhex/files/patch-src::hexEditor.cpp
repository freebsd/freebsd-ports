--- src/hexEditor.cpp.orig	Sun Feb  1 12:49:26 2004
+++ src/hexEditor.cpp	Sun Feb  1 20:48:29 2004
@@ -9,11 +9,12 @@
  *                                                                      
  *----------------------------------------------------------------------*/
 
-#include <assert.h>
-#include <stdio.h>
-#include <errno.h>
-#include <string.h>
-#include <ctype.h>
+#include <cassert>
+#include <cstdio>
+#include <cerrno>
+#include <cstring>
+#include <cctype>
+#include <cmath>
 #include <algorithm>
 #include <iostream>
 
