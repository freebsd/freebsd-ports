--- TIATracker.pro.orig	2021-01-22 16:22:27 UTC
+++ TIATracker.pro
@@ -120,33 +120,33 @@ INCLUDEPATH += $$PWD/sdl/windows/include
 DEPENDPATH += $$PWD/sdl/windows/include
 
 # Copy files to output directory
-install_it.path = $$OUT_PWD
+install_it.path = $$DESTDIR/$$PREFIX/test_it
 install_it.files = $$PWD/data/*
 
 INSTALLS += \
     install_it
 
 # Copy player to output directory
-install_player.path = $$OUT_PWD
+install_player.path = $$DESTDIR/$$PREFIX/test_player
 install_player.files = $$PWD/player
 
 INSTALLS += \
     install_player
 
 # Copy examples to output directory
-install_instruments.path = $$OUT_PWD
+install_instruments.path = $$DESTDIR/$$PREFIX/test_instr
 install_instruments.files = $$PWD/instruments
 
 INSTALLS += \
     install_instruments
 
-install_songs.path = $$OUT_PWD
+install_songs.path = $$DESTDIR/$$PREFIX/test_songs
 install_songs.files = $$PWD/songs
 
 INSTALLS += \
     install_songs
 
-install_guides.path = $$OUT_PWD
+install_guides.path = $$DESTDIR/$$PREFIX/test_guides
 install_guides.files = $$PWD/guides
 
 INSTALLS += \
