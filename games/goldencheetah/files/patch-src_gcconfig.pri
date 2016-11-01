--- src/gcconfig.pri.orig	2015-09-13 16:55:44 UTC
+++ src/gcconfig.pri
@@ -25,7 +25,7 @@
 # Let us know where flex and bison are installed.
 # You may need to specify the full path if things don't work.
 #QMAKE_LEX  = flex
-#QMAKE_YACC = bison
+QMAKE_YACC = bison
 #win32 {
 #  QMAKE_YACC = bison --file-prefix=y -t
 #  QMAKE_MOVE = cmd /c move
@@ -69,8 +69,8 @@
 # You may override the INCLUDE and LIB files if you like.
 # You *must* define KQOAUTH_INSTALL to use this feature.
 
-#KQOAUTH_INSTALL = 
-#KQOAUTH_INCLUDE =
+KQOAUTH_INSTALL = /usr/local
+KQOAUTH_INCLUDE = /usr/local/include/QtKOAuth
 #KQOAUTH_LIBS =
 
 # If you want 3D plotting, you need to install qwtplot3d
@@ -86,9 +86,9 @@
 # QWT3D_LIBS    = $${QWT3D_INSTALL}/lib/libqwtplot3d.a
 # You may override the INCLUDE and LIB files if you like.
 # You *must* define QWT3D_INSTALL to use this feature.
-#QWT3D_INSTALL = 
-#QWT3D_INCLUDE = 
-#QWT3D_LIBS    = 
+QWT3D_INSTALL = /usr/local
+QWT3D_INCLUDE = /usr/local/include/qwtplot3d-qt4
+QWT3D_LIBS    = /usr/local/lib/libqwtplot3d-qt4.so
 
 # For TrainingPeaks.com upload/download you need to install the Qt Soap add-on
 #     http://qt.nokia.com/products/appdev/add-on-products/catalog/4/Utilities/qtsoap
@@ -128,9 +128,9 @@
 # ICAL_LIBS    = $${ICAL_INSTALL}/lib/libical.a
 # You may override the INCLUDE and LIB files if you like.
 # You *must* define ICAL_INSTALL to use this feature.
-#ICAL_INSTALL = 
+ICAL_INSTALL = /usr/local
 #ICAL_INCLUDE = 
-#ICAL_LIBS    =
+ICAL_LIBS    = /usr/local/lib/libical.so
 
 # If you want support for using USB1 sticks in Train View on Windows
 # then install the SiLabs USBXpress Software Development Kit (SDK)
@@ -151,7 +151,7 @@
 #     http://sourceforge.net/projects/libusb-win32/files/libusb-win32-releases/0.1.12.2/
 # You may override the INCLUDE and LIB files if you like.
 # You *must* define LIBUSB_INSTALL to use this feature.
-#LIBUSB_INSTALL = /usr/local
+LIBUSB_INSTALL = /usr
 #LIBUSB_INCLUDE = 
 #LIBUSB_LIBS    = 
 
@@ -173,8 +173,8 @@
 # VLC_LIBS    = -lvlc -lvlccore
 # You may override the INCLUDE and LIB files if you like.
 # You *must* define VLC_INSTALL to use this feature.
-#VLC_INSTALL = 
-#VLC_INCLUDE = 
+VLC_INSTALL = /usr/local
+VLC_INCLUDE = /usr/local/include/libvlc
 #VLC_LIBS    = 
 
 # *** Mac users NOTE ***
@@ -235,7 +235,9 @@ macx {
 #DEFINES += GC_HAVE_DWM
 
 # What video playback do you want?
-DEFINES += GC_VIDEO_NONE             # dont add any video playback support
+#DEFINES += GC_VIDEO_NONE             # dont add any video playback support
 #DEFINES += GC_VIDEO_QUICKTIME        # mac only and the default
 #DEFINES += GC_VIDEO_QT5              # use QT5 qvideowidget if QT > 5.2.1
-#DEFINES += GC_VIDEO_VLC               # use VideoLan library needs VLC_INSTALL defined above
+DEFINES += GC_VIDEO_VLC               # use VideoLan library needs VLC_INSTALL defined above
+
+DEFINES += GC_VERSION=\\\"3.2.0\\\"
