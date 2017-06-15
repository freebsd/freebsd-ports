--- src/qt/qtbase/src/3rdparty/icu_dependency.pri.orig	2015-12-12 12:58:05 UTC
+++ src/qt/qtbase/src/3rdparty/icu_dependency.pri
@@ -10,7 +10,4 @@ win32 {
     }
 } else {
     LIBS_PRIVATE += -licui18n -licuuc -licudata
-    CONFIG(static) {
-      LIBS_PRIVATE += -ldl
-    }
 }
