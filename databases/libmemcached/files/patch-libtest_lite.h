--- libtest/lite.h.orig	2014-12-09 03:34:21 UTC
+++ libtest/lite.h
@@ -54,8 +54,10 @@
 #if defined(WIN32)
 # include <malloc.h>
 #else
+#ifdef HAVE_ALLOCA_H
 # include <alloca.h>
 #endif
+#endif
 
 #ifndef __PRETTY_FUNCTION__
 # define __PRETTY_FUNCTION__ __func__
