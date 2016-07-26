--- src/window.h.orig	2016-04-17 05:41:01 UTC
+++ src/window.h
@@ -23,7 +23,9 @@
 
 #include "config.h"
 
+#define _XOPEN_SOURCE_EXTENDED
 #include "curses.h"
+
 #include "gcc.h"
 
 #include <boost/optional.hpp>
