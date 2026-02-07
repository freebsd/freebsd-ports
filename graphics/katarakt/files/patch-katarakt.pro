--- katarakt.pro.orig	2017-08-23 19:28:21 UTC
+++ katarakt.pro
@@ -18,7 +18,8 @@ unix {
     isEmpty(PKG_CONFIG):PKG_CONFIG = pkg-config    # same as in link_pkgconfig.prf
     POPPLER_VERSION = $$system($$PKG_CONFIG --modversion $$POPPLER)
     POPPLER_VERSION_MAJOR = $$system(echo "$$POPPLER_VERSION" | cut -d . -f 1)
-    POPPLER_VERSION_MINOR = $$system(echo "$$POPPLER_VERSION" | cut -d . -f 2)
+    # With the new version scheme the minor version can have leading zeroes (calendar month)
+    POPPLER_VERSION_MINOR = $$system(echo "$$POPPLER_VERSION" | cut -d . -f 2 | sed "s|^0*||g")
     POPPLER_VERSION_MICRO = $$system(echo "$$POPPLER_VERSION" | cut -d . -f 3)
 
     DEFINES += POPPLER_VERSION_MAJOR=$$POPPLER_VERSION_MAJOR
@@ -57,3 +58,6 @@ web.depends = $$website.target
 web.CONFIG = phony
 
 QMAKE_EXTRA_TARGETS += documentation website doc web
+
+target.path = $$INSTALL_ROOT/$$PREFIX/bin/
+INSTALLS += target
