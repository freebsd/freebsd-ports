--- TeXworks.pro.orig	2015-04-03 18:05:39 UTC
+++ TeXworks.pro
@@ -108,7 +108,7 @@ unix:!macx { # on Unix-ish platforms we 
 	CONFIG		+= link_pkgconfig
 	PKGCONFIG	+= hunspell
 	PKGCONFIG	+= poppler-qt4
-	PKGCONFIG	+= zlib
+	PKGCONFIG	+= synctex zlib
 
 	# Enclose the path in \\\" (which later gets expanded to \", which in turn
 	# gets expanded to " in the c++ code)
@@ -180,8 +181,7 @@ HEADERS	+=	src/TWApp.h \
 			src/TWVersion.h \
 			src/TWTextCodecs.h \
 			src/SvnRev.h \
-			src/synctex_parser.h \
-			src/synctex_parser_utils.h \
+			src/TWSynchronizer.h \
 			src/ClickableLabel.h \
 			src/ConfigurableApp.h \
 			src/TWSystemCmd.h
@@ -225,8 +225,7 @@ SOURCES	+=	src/main.cpp \
 			src/ResourcesDialog.cpp \
 			src/ScriptManager.cpp \
 			src/ConfirmDelete.cpp \
-			src/synctex_parser.c \
-			src/synctex_parser_utils.c
+			src/TWSynchronizer.cpp
 
 RESOURCES	+=	res/resources.qrc \
 				res/resfiles.qrc
@@ -259,10 +258,10 @@ unix:!macx { # installation on Unix-ish 
 	isEmpty(DESKTOP_DIR):DESKTOP_DIR = $$DATA_DIR/applications
 
 	target.path = $$BIN_DIR
-	documentation.files = COPYING README NEWS
+	documentation.files = README NEWS
 	documentation.path = $$DOCS_DIR
 	manual.files = manual/*
-	manual.path = $$TW_HELPPATH
+	manual.path = DOCS_DIR
 	icon.files = res/images/TeXworks.png
 	icon.path = $$ICON_DIR
 	man.files = man/texworks.1
