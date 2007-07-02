--- ./qtemu.pro.orig	Mon Mar 19 15:56:21 2007
+++ ./qtemu.pro	Tue Jun 12 13:17:03 2007
@@ -21,10 +21,12 @@
   RC_FILE =     qtemu.rc
 }
 TEMPLATE =   app
-TRANSLATIONS =   translations/template_qtemu.ts \
-  translations/qtemu_de.ts \
+TRANSLATIONS =   translations/qtemu_de.ts \
   translations/qtemu_tr.ts \
   translations/qtemu_ru.ts \
   translations/qtemu_cz.ts \
   translations/qtemu_es.ts
-CONFIG +=   debug_and_release
+CONFIG +=   release
+
+system($$(LOCALBASE)/bin/lupdate-qt4 -verbose qtemu.pro)
+system($$(LOCALBASE)/bin/lrelease-qt4 -verbose qtemu.pro)
\ No newline at end of file
