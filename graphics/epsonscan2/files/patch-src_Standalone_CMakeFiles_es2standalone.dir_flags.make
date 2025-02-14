--- src/Standalone/CMakeFiles/es2standalone.dir/flags.make.orig	2024-09-12 07:10:30 UTC
+++ src/Standalone/CMakeFiles/es2standalone.dir/flags.make
@@ -4,7 +4,7 @@ CXX_FLAGS = -g -std=c++11 -O0    -fPIC
 # compile CXX with /usr/bin/c++
 CXX_FLAGS = -g -std=c++11 -O0    -fPIC
 
-CXX_DEFINES = -DBOOST_NO_CXX11_RVALUE_REFERENCES=1 -DQT_CORE_LIB -DQT_GUI_LIB -DQT_WIDGETS_LIB
+CXX_DEFINES = -DQT_CORE_LIB -DQT_GUI_LIB -DQT_WIDGETS_LIB
 
 CXX_INCLUDES = -I/home/build/shokaku/trunk/epsonscan2/src/Standalone -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/.. -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/../.. -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/../../.. -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/../Include -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/../CommonUtility -I/home/build/shokaku/trunk/epsonscan2/src/Standalone/../CommonUtility/utils -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -isystem /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++-64 
 
