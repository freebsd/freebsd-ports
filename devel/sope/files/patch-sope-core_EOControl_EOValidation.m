--- sope-core/EOControl/EOValidation.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOValidation.m
@@ -24,10 +24,6 @@
 #include "EONull.h"
 #include "common.h"
 
-#if __GNU_LIBOBJC__ >= 20100911
-#  define sel_get_any_uid sel_getUid
-#endif
-
 #if !LIB_FOUNDATION_LIBRARY
 
 @interface NSException(UsedSetUI) /* does Jaguar allow -setUserInfo: ? */
