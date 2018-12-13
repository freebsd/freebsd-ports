--- diffpdf.pro.orig	2013-10-15 07:01:22 UTC
+++ diffpdf.pro
@@ -31,35 +31,36 @@ TRANSLATIONS += diffpdf_fr.ts
 TRANSLATIONS += diffpdf_de.ts
 TRANSLATIONS += diffpdf_es.ts
 CODECFORTR    = UTF-8
-LIBS	     += -lpoppler-qt4
+LIBS	     += -lpoppler-qt5
+QT += widgets printsupport
 win32 {
     CONFIG += release
 }
 exists($(HOME)/opt/poppler024/) {
     message(Using locally built Poppler library)
     INCLUDEPATH += $(HOME)/opt/poppler024/include/poppler/cpp
-    INCLUDEPATH += $(HOME)/opt/poppler024/include/poppler/qt4
+    INCLUDEPATH += $(HOME)/opt/poppler024/include/poppler/qt5
     LIBS += -Wl,-rpath -Wl,$(HOME)/opt/poppler024/lib -L$(HOME)/opt/poppler024/lib
 } else {
     exists(/poppler_lib) {
 	message(Using locally built Poppler library on Windows)
 	INCLUDEPATH += /c/poppler_lib/include/poppler/cpp
-	INCLUDEPATH += /c/poppler_lib/include/poppler/qt4
+	INCLUDEPATH += /c/poppler_lib/include/poppler/qt5
 	LIBS += -Wl,-rpath -Wl,/c/poppler_lib/bin -Wl,-L/c/poppler_lib/bin
     } else {
-	exists(/usr/include/poppler/qt4) {
+	exists(/usr/include/poppler/qt5) {
 	    INCLUDEPATH += /usr/include/poppler/cpp
-	    INCLUDEPATH += /usr/include/poppler/qt4
+	    INCLUDEPATH += /usr/include/poppler/qt5
 	} else {
 	    INCLUDEPATH += /usr/local/include/poppler/cpp
-	    INCLUDEPATH += /usr/local/include/poppler/qt4
+	    INCLUDEPATH += /usr/local/include/poppler/qt5
 	}
     }
 }
 #exists($(HOME)/opt/podofo09/) {
 #    message(Using locally built PoDoFo library)
 #    INCLUDEPATH += $(HOME)/opt/podofo09/include/poppler/cpp
-#    INCLUDEPATH += $(HOME)/opt/podofo09/include/poppler/qt4
+#    INCLUDEPATH += $(HOME)/opt/podofo09/include/poppler/qt5
 #    LIBS += -Wl,-rpath -Wl,$(HOME)/opt/podofo09/lib64 -Wl,-L$(HOME)/opt/podofo09/lib64
 #} else {
 #    exists(/usr/include/podofo) {
