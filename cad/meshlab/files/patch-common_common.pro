--- common/common.pro.orig	2014-02-07 09:38:24 UTC
+++ common/common.pro
@@ -126,6 +126,8 @@ SOURCES += filterparameter.cpp \
 #win32-msvc2008:LIBS	+= ../external/lib/win32-msvc2008/jhead.lib
 #win32-msvc2010:LIBS	+= ../external/lib/win32-msvc2010/jhead.lib
 #win32-msvc2012:LIBS	+= ../external/lib/win32-msvc2012/jhead.lib
+
+CONFIG +=    static
 #win32-g++:LIBS		+= -L../external/lib/win32-gcc -ljhead
 #linux-g++:LIBS		+= -L../external/lib/linux-g++ -ljhead
 #linux-g++-32:LIBS		+= -L../external/lib/linux-g++-32 -ljhead
