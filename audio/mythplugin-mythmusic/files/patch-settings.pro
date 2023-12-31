--- settings.pro.orig	2023-03-19 16:48:43.345465000 +0000
+++ settings.pro	2023-03-19 16:42:27.786115000 +0000
@@ -8,7 +8,7 @@
 include(settings2.pro)
 
 MY_INSTALL_INCLUDE = $${SYSROOT}$${PREFIX}/include
-!contains(MY_INSTALL_INCLUDE, /usr/include$) {
+!contains(MY_INSTALL_INCLUDE, /usr/local/include$) {
     INCLUDEPATH += $${SYSROOT}$${PREFIX}/include
 }
 
