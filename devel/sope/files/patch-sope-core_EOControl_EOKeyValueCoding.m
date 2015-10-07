--- sope-core/EOControl/EOKeyValueCoding.m.orig	2015-09-16 18:26:49 UTC
+++ sope-core/EOControl/EOKeyValueCoding.m
@@ -26,7 +26,6 @@
 #if GNU_RUNTIME
 
 #if __GNU_LIBOBJC__ >= 20100911
-#  define sel_get_any_uid sel_getUid
 #  include <objc/runtime.h>
 #else
 #  include <objc/encoding.h>
