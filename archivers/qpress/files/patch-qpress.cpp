--- qpress.cpp.orig	2013-11-02 00:43:30.451058000 +0000
+++ qpress.cpp
@@ -88,6 +88,7 @@ and finally outputs an UPDIR:
 
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <stdio.h>
 #include "aio.hpp"
 #include <stdarg.h>
