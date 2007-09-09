--- project.pro.orig	Sat Jul 14 21:44:28 2007
+++ project.pro	Sun Sep  9 21:54:27 2007
@@ -171,13 +171,13 @@
 menu.files       = qtpfsgui.desktop
 menu.path        = $${PREFIX}/share/applications
 icon.files       = images/qtpfsgui.png
-icon.path        = $${PREFIX}/share/icons/hicolor/48x48/apps
-htmls.files      = html
-htmls.path       = $${PREFIX}/share/qtpfsgui
+icon.path        = $${PREFIX}/share/pixmaps
+docs.files      = AUTHORS COPYING Changelog INSTALL NEWS README TODO html
+docs.path       = $${PREFIX}/share/doc/qtpfsgui
 i18n.files       = i18n/lang_de.qm i18n/lang_es.qm i18n/lang_it.qm i18n/lang_fr.qm i18n/lang_pl.qm i18n/lang_tr.qm
 i18n.path        = $$I18NDIR
 
-INSTALLS        += target menu icon htmls i18n
+INSTALLS        += target menu icon docs i18n
 message ( "" )
 message ("********************************************************************")
 message ("Installation PREFIX=$$PREFIX")
@@ -191,7 +191,7 @@
 message ("qtpfsgui ==> $$target.path")
 message ("qtpfsgui.desktop ==> $$menu.path")
 message ("qtpfsgui.png ==> $$icon.path")
-message ("html directory ==> $$htmls.path")
+message ("doc directory ==> $$docs.path")
 message ("i18n messages ==> $$i18n.path")
 message ("********************************************************************")
 
