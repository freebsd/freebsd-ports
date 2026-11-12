--- katarakt.pro.orig	2017-08-23 19:28:21 UTC
+++ katarakt.pro
@@ -57,3 +58,6 @@ web.depends = $$website.target
 web.CONFIG = phony
 
 QMAKE_EXTRA_TARGETS += documentation website doc web
+
+target.path = $$INSTALL_ROOT/$$PREFIX/bin/
+INSTALLS += target
