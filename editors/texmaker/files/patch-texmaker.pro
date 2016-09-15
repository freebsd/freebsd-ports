--- texmaker.pro.orig	2015-10-24 09:05:27 UTC
+++ texmaker.pro
@@ -19,11 +19,11 @@ DEFINES += HAVE_SPLASH
 unix:!macx {
 contains( QT_VERSION, "^5.*" ) {
 CONFIG		+= link_pkgconfig
-PKGCONFIG 	= poppler-qt5
+PKGCONFIG 	= hunspell poppler-qt5
 DEFINES += POPPLER24
 } else {
 CONFIG		+= link_pkgconfig
-PKGCONFIG 	= poppler-qt4
+PKGCONFIG 	= hunspell poppler-qt4
 DETECTEDPOPPLER=$$system(pkg-config --modversion poppler)
 contains( DETECTEDPOPPLER, "^0.18.*" ){
 DEFINES += OLDPOPPLER
@@ -98,25 +98,6 @@ HEADERS	+= texmaker.h \
 	unicodeview.h \
 	quickbeamerdialog.h \
 	svnhelper.h \
-	hunspell/affentry.hxx \
-	hunspell/affixmgr.hxx \
-	hunspell/atypes.hxx \
-	hunspell/baseaffix.hxx \
-	hunspell/csutil.hxx \
-	hunspell/dictmgr.hxx \
-	hunspell/hashmgr.hxx \
-	hunspell/htypes.hxx \
-	hunspell/hunspell.hxx \
-	hunspell/hunspell.h \
-	hunspell/langnum.hxx \
-	hunspell/license.hunspell \
-	hunspell/phonet.hxx \
-	hunspell/suggestmgr.hxx \
-	hunspell/license.myspell \
-	hunspell/filemgr.hxx \
-	hunspell/hunzip.hxx \
-	hunspell/replist.hxx \
-	hunspell/w_char.hxx \
 	singleapp/qtlocalpeer.h \
 	singleapp/qtlockedfile.h \
 	singleapp/qtsingleapplication.h \
@@ -210,18 +191,6 @@ SOURCES	+= main.cpp \
 	unicodeview.cpp \
 	quickbeamerdialog.cpp \
 	svnhelper.cpp \
-	hunspell/affentry.cxx \
-	hunspell/affixmgr.cxx \
-	hunspell/csutil.cxx \
-	hunspell/dictmgr.cxx \
-	hunspell/hashmgr.cxx \
-	hunspell/hunspell.cxx \
-	hunspell/phonet.cxx \
-	hunspell/suggestmgr.cxx \
-	hunspell/utf_info.cxx \
-	hunspell/filemgr.cxx \
-	hunspell/replist.cxx \
-	hunspell/hunzip.cxx \
 	singleapp/qtlocalpeer.cpp \
 	singleapp/qtlockedfile.cpp \
 	singleapp/qtsingleapplication.cpp \
@@ -395,13 +364,6 @@ utilities.files = doc/doc1.png \
 	utilities/AUTHORS \
 	utilities/COPYING \
 	utilities/CHANGELOG.txt \
-	utilities/texmaker16x16.png \
-	utilities/texmaker22x22.png \
-	utilities/texmaker32x32.png \
-	utilities/texmaker48x48.png \
-	utilities/texmaker64x64.png \
-	utilities/texmaker128x128.png \
-	utilities/texmaker.svg \
 	scripts/titlecase_selection.tms \
 	scripts/hardwordwrap_selection_80col.tms \
 	locale/qt_cs.qm \
@@ -477,4 +439,20 @@ INSTALLS += desktop
 
 icon.files = utilities/texmaker.png
 INSTALLS += icon
+
+icon16.path = $${PREFIX}/share/icons/hicolor/16x16/apps
+icon16.files= utilities/texmaker16x16.png
+icon22.path = $${PREFIX}/share/icons/hicolor/22x22/apps
+icon22.files= utilities/texmaker22x22.png
+icon32.path=  $${PREFIX}/share/icons/hicolor/32x32/apps
+icon32.files= utilities/texmaker32x32.png
+icon48.path=  $${PREFIX}/share/icons/hicolor/48x48/apps
+icon48.files=  utilities/texmaker48x48.png
+icon64.path=  $${PREFIX}/share/icons/hicolor/64x64/apps
+icon64.files= utilities/texmaker64x64.png
+icon128.path=  $${PREFIX}/share/icons/hicolor/128x128/apps
+icon128.files=utilities/texmaker128x128.png
+iconscale.path=$${PREFIX}/share/icons/hicolor/scalable/apps
+iconscale.files=utilities/texmaker.svg
+INSTALLS += icon16 icon22 icon32 icon48 icon64 icon128 iconscale
 }
