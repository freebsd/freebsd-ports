--- ./src/gui/pdfedit.pro.orig	Sun Apr 29 14:28:52 2007
+++ ./src/gui/pdfedit.pro	Thu May  3 15:00:01 2007
@@ -240,7 +240,7 @@
 }
 
 #OutputDevice
-LIBS += -lqoutputdevices -L../kpdf-kde-3.3.2
+LIBS += -lqoutputdevices -L../kpdf-kde-3.3.2 -L$$LOCALBASE/lib -lt1
 
 include(../kernel/kernel-obj.pro)
 
