--- sope-mime/NGMime/common.h.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGMime/common.h
@@ -37,7 +37,9 @@
 #include "NGMimeType.h"
 
 #if !GNU_RUNTIME
-#  ifndef sel_eq
+#  if (defined(__GNU_LIBOBJC__) && (__GNU_LIBOBJC__ >= 20100911)) || defined(APPLE_RUNTIME) || defined(__GNUSTEP_RUNTIME__)
+#    define sel_eq(__A__,__B__) sel_isEqual(__A__,__B__)
+#  else ifndef sel_eq
 #    define sel_eq(__A__, __B__) (__A__==__B__)
 #  endif
 #endif
