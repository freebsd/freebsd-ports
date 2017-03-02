--- sv.pro.orig	2015-10-22 11:26:02 UTC
+++ sv.pro
@@ -41,6 +41,7 @@ QT += network xml gui widgets
 
 TARGET = "Sonic Visualiser"
 linux*:TARGET = sonic-visualiser
+freebsd*:TARGET = sonic-visualiser
 solaris*:TARGET = sonic-visualiser
 
 DEPENDPATH += . svcore svgui svapp
