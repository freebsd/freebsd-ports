--- lib/c_wrapper.cpp.orig	2010-06-07 10:43:52.147054247 +0300
+++ lib/c_wrapper.cpp	2010-06-07 10:44:16.392713467 +0300
@@ -42,6 +42,7 @@
 #define TR_OBJ_CHECKV(o) Track *obj = (Track *)t; \
                          if (obj == NULL) return;
 
+#include <stdlib.h>
 #include <deque>
 
 class NotifyData
