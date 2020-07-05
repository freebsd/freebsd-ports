--- katarakt.pro.orig	2019-12-29 14:08:42 UTC
+++ katarakt.pro
@@ -57,3 +57,6 @@ web.depends = $$website.target
 web.CONFIG = phony
 
 QMAKE_EXTRA_TARGETS += documentation website doc web
+
+target.path = $$INSTALL_ROOT/$$PREFIX/bin/
+INSTALLS += target
