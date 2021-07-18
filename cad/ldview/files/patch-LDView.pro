--- LDView.pro.orig	2021-06-05 07:06:46 UTC
+++ LDView.pro
@@ -78,9 +78,9 @@ MAKEOPT += POSTFIX=$$POSTFIX
 OBJECTS_DIR = .obj$$POSTFIX
 MAKEOPT += \"TESTING=-I$$[QT_INSTALL_HEADERS] $$QMAKE_CXXFLAGS_STATIC_LIB $(TESTING)\"
 
-!freebsd {
+#!freebsd {
 DEFINES 	+= EXPORT_3DS
-}
+#}
 #DEFINES 	+= _NO_BOOST
 
 QMAKE_CXXFLAGS       += $(Q_CXXFLAGS)
@@ -93,7 +93,7 @@ freebsd {
 message("FreeBSD")
 MAKE = gmake
 DEFINES += USE_CPP11
-MAKEOPT += EXPORT_3DS=
+#MAKEOPT += EXPORT_3DS=
 }
 
 contains(USE_CPP11,NO){
