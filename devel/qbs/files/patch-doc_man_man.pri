--- doc/man/man.pri.orig	2017-12-26 13:19:41 UTC
+++ doc/man/man.pri
@@ -1,5 +1,5 @@
 qbs_no_man_install: return()
 
 man.files = $$PWD/qbs.1
-man.path = $${QBS_INSTALL_PREFIX}/share/man/man1
+man.path = $${QBS_INSTALL_PREFIX}/man/man1
 INSTALLS += man
