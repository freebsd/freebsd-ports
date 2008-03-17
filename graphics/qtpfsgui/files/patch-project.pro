--- project.pro.orig	2008-02-16 11:43:24.000000000 +0100
+++ project.pro	2008-03-17 17:18:14.000000000 +0100
@@ -298,13 +298,13 @@
 menu.files       = qtpfsgui.desktop
 menu.path        = $${PREFIX}/share/applications
 icon.files       = images/qtpfsgui.png
-icon.path        = $${PREFIX}/share/icons/hicolor/48x48/apps
+icon.path        = $${PREFIX}/share/pixmaps
 htmls.files      = html
-htmls.path       = $${PREFIX}/share/qtpfsgui
+htmls.path       = $${PREFIX}/share/doc/qtpfsgui
 i18n.files       = i18n/lang_de.qm i18n/lang_es.qm i18n/lang_it.qm i18n/lang_fr.qm i18n/lang_pl.qm i18n/lang_tr.qm i18n/lang_ru.qm i18n/lang_cs.qm
 i18n.path        = $$I18NDIR
 docs.files       = README LICENSE AUTHORS INSTALL Changelog
-docs.path        = $${PREFIX}/share/qtpfsgui
+docs.path        = $${PREFIX}/share/doc/qtpfsgui
 
 INSTALLS        += target menu icon htmls i18n docs
 message ( "" )
@@ -320,7 +320,7 @@
 message ("qtpfsgui         ==> $$target.path")
 message ("qtpfsgui.desktop ==> $$menu.path")
 message ("qtpfsgui.png     ==> $$icon.path")
-message ("html and docs    ==> $$htmls.path")
+message ("html             ==> $$docs.path")
 message ("i18n messages    ==> $$i18n.path")
 message ("********************************************************************")
 
