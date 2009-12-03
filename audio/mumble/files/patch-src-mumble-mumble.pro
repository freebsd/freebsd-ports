--- src/mumble/mumble.pro.orig	2009-03-22 16:05:00.000000000 +0100
+++ src/mumble/mumble.pro	2009-12-02 23:09:37.000000000 +0100
@@ -113,6 +113,13 @@
     SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
   }
 
+  contains(UNAME, FreeBSD) {
+    CONFIG *= oss
+    HEADERS *= GlobalShortcut_unix.h
+    SOURCES *= GlobalShortcut_unix.cpp TextToSpeech_unix.cpp Overlay_unix.cpp
+    LIBS *= -lssl
+  }
+
   macx {
     TARGET = Mumble
     ICON = ../../icons/mumble.icns
@@ -217,7 +224,7 @@
 	QT_TRANSDIR = $$[QT_INSTALL_TRANSLATIONS]/
 	QT_TRANSDIR = $$replace(QT_TRANSDIR,/,$${DIR_SEPARATOR})
 
-	QT_TRANSLATION_FILES *= qt_de.qm qt_es.qm qt_fr.qm qt_ru.qm qt_pl.qm qt_ja_jp.qm
+	QT_TRANSLATION_FILES *= qt_de.ts qt_es.ts qt_fr.ts qt_ru.ts qt_pl.ts qt_ja_JP.ts
 
 	copytrans.output = ${QMAKE_FILE_NAME}
 	copytrans.commands = $$QMAKE_COPY $${QT_TRANSDIR}${QMAKE_FILE_NAME} ${QMAKE_FILE_OUT}
