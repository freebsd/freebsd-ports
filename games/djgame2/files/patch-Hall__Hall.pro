--- Hall/Hall.pro.orig	2014-10-30 15:03:41.000000000 +0300
+++ Hall/Hall.pro	2014-10-30 15:04:05.000000000 +0300
@@ -13,6 +13,7 @@
 QT 				+= 	network xml svg
 
 LIBS			+=	../Base/build/libBaseStatic.a
+LIBS			+=	-lX11
 #LIBS			+=	./libspeex.a
 
 INCLUDEPATH 	+=	../Base/src include
