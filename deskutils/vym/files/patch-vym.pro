--- ./vym.pro.orig	2011-01-24 18:42:33.000000000 +0300
+++ ./vym.pro	2011-07-03 16:02:05.500883581 +0400
@@ -217,7 +217,7 @@
 target.path = $${BINDIR}
 INSTALLS += target
 
-support.files = styles/ scripts/ icons/ flags/ lang/ macros/ exports/ demos/
+support.files = styles/ scripts/ icons/ flags/ macros/ exports/ demos/
 support.path = $${DATADIR}/vym
 INSTALLS += support 
 
