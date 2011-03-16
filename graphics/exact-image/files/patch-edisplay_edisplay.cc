--- ./edisplay/edisplay.cc.orig	2011-03-15 09:03:47.000000000 -0400
+++ ./edisplay/edisplay.cc	2011-03-15 09:05:59.000000000 -0400
@@ -27,7 +27,11 @@
 #include "Evas_Engine_GL_X11.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 #include <algorithm>
 #include <iostream>
 #include <sstream>
