--- src/mixxx.pro.orig	Mon Oct 11 11:58:09 2004
+++ src/mixxx.pro	Tue Oct 12 21:50:29 2004
@@ -31,15 +31,7 @@
 DEFINES += __PORTAUDIO__
 SOURCES += playerportaudio.cpp
 HEADERS += playerportaudio.h
-PORTAUDIO_DIR = ../lib/portaudio-v18
-INCLUDEPATH += $$PORTAUDIO_DIR/pa_common
-HEADERS += $$PORTAUDIO_DIR/pa_common/portaudio.h
 unix {
-SOURCES += $$PORTAUDIO_DIR/pa_common/pa_lib.c $$PORTAUDIO_DIR/pa_common/pa_convert.c
-HEADERS += $$PORTAUDIO_DIR/pa_common/pa_host.h
-unix:!macx:SOURCES += $$PORTAUDIO_DIR/pablio/ringbuffer.c $$PORTAUDIO_DIR/pa_unix_oss/pa_unix.c $$PORTAUDIO_DIR/pa_unix_oss/pa_unix_oss.c
-unix:!macx:HEADERS += $$PORTAUDIO_DIR/pablio/ringbuffer.h $$PORTAUDIO_DIR/pa_unix_oss/pa_unix.h
-unix:!macx:INCLUDEPATH += $$PORTAUDIO_DIR/pa_unix_oss
 macx:SOURCES += $$PORTAUDIO_DIR/pablio/ringbuffer.c $$PORTAUDIO_DIR/pa_mac_core/pa_mac_core.c
 macx:LIBS += -framework CoreAudio -framework AudioToolbox
 macx:INCLUDEPATH += $$PORTAUDIO_DIR/pa_mac_core $$PORTAUDIO_DIR/pablio 
@@ -136,8 +128,6 @@
 # PowerMate
 SOURCES += powermate.cpp
 HEADERS += powermate.h
-unix:!macx:SOURCES += powermatelinux.cpp
-unix:!macx:HEADERS += powermatelinux.h
 win32:SOURCES += powermatewin.cpp
 win32:HEADERS += powermatewin.h
 win32:LIBS += setupapi.lib
@@ -145,16 +135,14 @@
 # Mouse
 SOURCES += mouse.cpp
 HEADERS += mouse.h
-unix:!macx:SOURCES += mouselinux.cpp
-unix:!macx:HEADERS += mouselinux.h
+#unix:!macx:SOURCES += mouselinux.cpp
+#unix:!macx:HEADERS += mouselinux.h
 #win32:SOURCES += mousewin.cpp
 #win32:HEADERS += mousewin.h
 
 # Joystick
 SOURCES += joystick.cpp
 HEADERS += joystick.h
-unix:!macx:SOURCES += joysticklinux.cpp
-unix:!macx:HEADERS += joysticklinux.h
 
 # KissFFT
 KISSFFT_DIR = ../lib/kissfft
@@ -163,9 +151,8 @@
 INCLUDEPATH += $$KISSFFT_DIR
 
 # Audio scaling
-INCLUDEPATH += ../lib/libsamplerate
-SOURCES += enginebufferscalesrc.cpp ../lib/libsamplerate/samplerate.c ../lib/libsamplerate/src_linear.c ../lib/libsamplerate/src_sinc.c ../lib/libsamplerate/src_zoh.c
-HEADERS += enginebufferscalesrc.h ../lib/libsamplerate/samplerate.h ../lib/libsamplerate/config.h ../lib/libsamplerate/common.h ../lib/libsamplerate/float_cast.h ../lib/libsamplerate/fastest_coeffs.h ../lib/libsamplerate/high_qual_coeffs.h ../lib/libsamplerate/mid_qual_coeffs.h
+SOURCES += enginebufferscalesrc.cpp
+HEADERS += enginebufferscalesrc.h
 
 # Debug plotting through gplot API
 #unix:DEFINES += __GNUPLOT__
@@ -197,7 +184,6 @@
 
   SETTINGS_FILE = \".mixxx.cfg\"
   TRACK_FILE = \".mixxxtrack.xml\"
-  DEFINES += __LINUX__
 }
 
 unix {
@@ -259,23 +245,12 @@
    keyb.path = $${UNIX_SHARE_PATH}/keyboard
    keyb.files = keyboard/*
 
-    # doc files...
-   readme.path = $${PREFIX}/share/doc/mixxx-1.3
-   readme.files = ../README
-   licence.path = $${PREFIX}/share/doc/mixxx-1.3
-   licence.files = ../LICENSE
-   copying.path = $${PREFIX}/share/doc/mixxx-1.3
-   copying.files = ../COPYING
-   manual.path = $${PREFIX}/share/doc/mixxx-1.3
-   manual.files = ../Mixxx-Manual.pdf
-
-
     # binary...
    TARGET = mixxx
    target.path = $${PREFIX}/bin
 
     # finally adding what we wanna install...
-   INSTALLS += skino skinoc skinos skint midi keyb readme licence copying manual target
+   INSTALLS += skino skinoc skinos skint midi keyb target
 }
 
 
@@ -295,6 +270,10 @@
 # Socket
 SOURCES += mixxxsocketserver.cpp mixxxsocketclient.cpp #mixxxsocketcli.cpp
 HEADERS += mixxxsocketserver.h mixxxsocketclient.h #mixxxsocket.cli.h
+
+# compat_round()
+SOURCES += compat_round.cpp
+HEADERS += compat_round.h
 
 IMAGES += icon.png
 DEFINES += SETTINGS_FILE=$$SETTINGS_FILE TRACK_FILE=$$TRACK_FILE
