--- ./qtemu.pro.orig	Sat Jul 14 01:37:06 2007
+++ ./qtemu.pro	Sat Jul 14 12:59:09 2007
@@ -21,7 +21,7 @@
   RC_FILE =     qtemu.rc
 }
 TEMPLATE =   app
-TRANSLATIONS =   translations/template_qtemu.ts \
+TRANSLATIONS =   \
   translations/qtemu_de.ts \
   translations/qtemu_tr.ts \
   translations/qtemu_ru.ts \
@@ -29,4 +29,4 @@
   translations/qtemu_fr.ts \
   translations/qtemu_it.ts \
   translations/qtemu_es.ts
-CONFIG +=   debug_and_release
+CONFIG +=   release
