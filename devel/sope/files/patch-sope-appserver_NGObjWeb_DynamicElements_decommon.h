--- sope-appserver/NGObjWeb/DynamicElements/decommon.h.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/DynamicElements/decommon.h
@@ -35,6 +35,10 @@
 @end
 #endif
 
+#if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
+#  define sel_get_name(__XXX__) sel_getName(__XXX__)
+#endif
+
 #include <NGExtensions/NGExtensions.h>
 #include "WOResponse+private.h"
 #include <NGObjWeb/WOContext.h>
