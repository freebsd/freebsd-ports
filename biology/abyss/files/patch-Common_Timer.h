--- Common/Timer.h.orig	2019-02-25 02:35:12 UTC
+++ Common/Timer.h
@@ -3,6 +3,8 @@
 
 #include <string>
 
+#include <time.h>
+
 /**
  * Time the duration between the construction and destruction of this
  * timer object and log that duration.
