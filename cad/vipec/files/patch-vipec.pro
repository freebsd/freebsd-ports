--- vipec.pro.orig	Thu Oct  2 04:58:40 2003
+++ vipec.pro	Sat Aug 21 00:04:24 2004
@@ -8,8 +8,8 @@
 CLEAN_FILES	= core Makefile *~ *moc* components/*~ dialogs/*~ images/*~ outputs/*~ widgets/*~
 MOC_DIR		= moc
 OBJECTS_DIR = obj
-CONFIG		= qt warn_on exceptions stl rtti
-DEFINES		= QT_FATAL_ASSERT 
+CONFIG		+= qt warn_on exceptions stl rtti
+DEFINES		+= QT_FATAL_ASSERT VIPECHOME=\"$(VIPECHOME)\" 
 RC_FILE		= vipec.rc
 HEADERS	= 	\
 		../include/Logger.h \
