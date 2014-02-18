--- lib/http/src/Http.cpp.orig	2014-02-15 18:56:59.580491668 +0100
+++ lib/http/src/Http.cpp	2014-02-15 18:57:10.490545507 +0100
@@ -31,6 +31,7 @@
 
 #include "config.h"
 #include <stdio.h> 
+#include <stdlib.h> 
 #include <sys/types.h>
 #include <sys/stat.h>
 #ifndef WIN32
