--- qmake/builddir.pri.orig	2019-10-20 18:28:58 UTC
+++ qmake/builddir.pri
@@ -33,20 +33,7 @@ isEmpty(TOP_BUILDDIR) {
   TOP_BUILDDIR = $$TOP_SRCDIR
 }
 
-# If the build and source paths are equal,
-# it's not a shadow build.
-equals(TOP_BUILDDIR, $$TOP_SRCDIR) {
-  CONFIG(debug, debug|release) {
-    DESTDIR = $$TOP_BUILDDIR/debug
-  }
-
-  CONFIG(release, debug|release) {
-    DESTDIR = $$TOP_BUILDDIR/release
-  }
-} else {
-  DESTDIR = $$TOP_BUILDDIR
-}
-
+DESTDIR = $$TOP_BUILDDIR/release
 OBJECTS_ROOT = $$DESTDIR/.obj
 MOC_ROOT = $$DESTDIR/.moc
 RCC_ROOT = $$DESTDIR/.qrc
