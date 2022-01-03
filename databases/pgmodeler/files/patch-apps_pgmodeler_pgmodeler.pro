--- apps/pgmodeler/pgmodeler.pro.orig	2022-01-03 15:32:35 UTC
+++ apps/pgmodeler/pgmodeler.pro
@@ -17,7 +17,8 @@ unix|windows: LIBS += $$LIBGUI_LIB \
 		      $$LIBCONNECTOR_LIB \
 		      $$LIBCORE_LIB \
 		      $$LIBPARSERS_LIB \
-		      $$LIBUTILS_LIB
+		      $$LIBUTILS_LIB \
+		      $$QMAKE_LIBS_EXECINFO
 
 INCLUDEPATH += $$LIBGUI_INC \
 	       $$LIBCANVAS_INC \
