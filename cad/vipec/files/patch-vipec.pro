--- vipec.pro.orig	Thu Oct  2 04:58:40 2003
+++ vipec.pro	Mon Jan 26 00:17:52 2004
@@ -8,7 +8,7 @@
 CLEAN_FILES	= core Makefile *~ *moc* components/*~ dialogs/*~ images/*~ outputs/*~ widgets/*~
 MOC_DIR		= moc
 OBJECTS_DIR = obj
-CONFIG		= qt warn_on exceptions stl rtti
+CONFIG		= qt warn_on exceptions stl rtti thread release
 DEFINES		= QT_FATAL_ASSERT 
 RC_FILE		= vipec.rc
 HEADERS	= 	\
