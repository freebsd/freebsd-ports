--- qpress.cpp.orig	2016-07-26 12:20:52 UTC
+++ qpress.cpp
@@ -88,6 +88,7 @@ and finally outputs an UPDIR:
 
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <stdio.h>
 #include "aio.hpp"
 #include <stdarg.h>
