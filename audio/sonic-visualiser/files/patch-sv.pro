--- sv.pro.orig	2019-12-10 09:29:11 UTC
+++ sv.pro
@@ -15,6 +15,7 @@ QT += network xml gui widgets svg
 
 TARGET = "Sonic Visualiser"
 linux*:TARGET = sonic-visualiser
+freebsd*:TARGET = sonic-visualiser
 solaris*:TARGET = sonic-visualiser
 
 !win32 {
