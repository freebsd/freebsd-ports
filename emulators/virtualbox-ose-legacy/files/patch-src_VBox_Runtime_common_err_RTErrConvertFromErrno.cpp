--- src/VBox/Runtime/common/err/RTErrConvertFromErrno.cpp.orig	2018-01-15 14:56:07 UTC
+++ src/VBox/Runtime/common/err/RTErrConvertFromErrno.cpp
@@ -302,7 +302,7 @@ RTDECL(int)  RTErrConvertFromErrno(unsigned uNativeCod
         case EILSEQ:            return VERR_NO_TRANSLATION;
 #endif
 #ifdef ERESTART
-        case ERESTART:          return VERR_INTERRUPTED;/** @todo fix duplicate error?*/
+        case (unsigned)ERESTART: return VERR_INTERRUPTED;/** @todo fix duplicate error?*/
 #endif
 #ifdef ESTRPIPE
         //case ESTRPIPE 86      /* Streams pipe error */
