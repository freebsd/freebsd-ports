--- ./plugins/plugins.pri.orig	2011-08-23 19:12:08.000000000 +0000
+++ ./plugins/plugins.pri	2012-09-13 21:26:13.620559681 +0000
@@ -6,6 +6,7 @@
 #CONFIG  += silent
 DESTDIR  = $$EDB_ROOT
 INSTALLS += target
+target.path = $$DEFAULT_PLUGIN_PATH
 
 DEFINES += EDB_PLUGIN
 
@@ -54,7 +55,6 @@
 	!macx {
 		INCLUDEPATH += $$EDB_ROOT/include/arch/$$QT_ARCH
 		DEPENDPATH  += $$EDB_ROOT/include/arch/$$QT_ARCH
-		include(plugins-$${QT_ARCH}.pri)
 	}
 
     debug:OBJECTS_DIR   = $${OUT_PWD}/.obj/debug-shared
