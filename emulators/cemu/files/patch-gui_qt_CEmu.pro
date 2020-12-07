--- gui/qt/CEmu.pro.orig	2019-06-22 09:20:44 UTC
+++ gui/qt/CEmu.pro
@@ -6,7 +6,7 @@ lessThan(QT_MINOR_VERSION, 5) : error("You need at lea
 
 # CEmu version and info
 CEMU_RELEASE = true
-CEMU_GIT_SHA = $$system(git describe --abbrev=7 --always)
+CEMU_GIT_SHA = 87c3b43 # XXX: don't forget to change for the next version!
 isEmpty(CEMU_VERSION) {
     CEMU_VERSION = v1.3dev
     CEMU_RELEASE = false
@@ -23,7 +23,7 @@ CI = $$(CI)
 DISTFILES += ../../.astylerc
 
 # Linux desktop files
-if (linux) {
+if (unix) {
     isEmpty(PREFIX) {
         PREFIX = /usr
     }
@@ -77,12 +77,13 @@ if (!win32-msvc*) {
     isEmpty(CI) {
         # Only enable opts for non-CI release builds
         # -flto might cause an internal compiler error on GCC in some circumstances (with -g3?)... Comment it if needed.
-        CONFIG(release, debug|release): GLOBAL_FLAGS += -O3 -flto
+        #CONFIG(release, debug|release): GLOBAL_FLAGS += -O3 -flto
     }
 
     if (contains(DEFINES, LIB_ARCHIVE_SUPPORT)) {
         CONFIG += link_pkgconfig
-        PKGCONFIG += zlib libarchive
+        PKGCONFIG += zlib
+        LIBS += -larchive
     }
     # You should run ./capture/get_libpng-apng.sh first!
     isEmpty(USE_LIBPNG) {
@@ -157,7 +158,7 @@ if (!win32-msvc*) {
     }
 }
 
-if (macx|linux) {
+if (macx|unix) {
     # Be more secure by default...
     GLOBAL_FLAGS    += -fPIE -Wstack-protector -fstack-protector-strong --param=ssp-buffer-size=1
     # Use ASAN on debug builds. Watch out about ODR crashes when built with -flto. detect_odr_violation=0 as an env var may help.
@@ -165,7 +166,7 @@ if (macx|linux) {
 }
 
 macx:  QMAKE_LFLAGS += -Wl,-dead_strip
-linux: QMAKE_LFLAGS += -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wl,--gc-sections -pie
+unix: QMAKE_LFLAGS += -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wl,--gc-sections -pie
 
 QMAKE_CFLAGS    += $$GLOBAL_FLAGS
 QMAKE_CXXFLAGS  += $$GLOBAL_FLAGS
@@ -256,7 +257,7 @@ SOURCES += \
     keyhistorywidget.cpp \
     tablewidget.cpp
 
-linux|macx: SOURCES += ../../core/os/os-linux.c
+unix|macx: SOURCES += ../../core/os/os-linux.c
 win32: SOURCES += ../../core/os/os-win32.c win32-console.cpp
 win32: LIBS += -lpsapi
 
