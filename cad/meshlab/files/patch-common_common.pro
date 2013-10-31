--- common/common.pro.orig	2013-10-31 13:57:32.000000000 +0100
+++ common/common.pro	2013-10-31 14:00:10.000000000 +0100
@@ -126,3 +126,5 @@
 linux-g++-64:LIBS		+= -L../external/lib/linux-g++-64 -ljhead
 	
 #RESOURCES = common.qrc
+
+CONFIG +=    static
