--- src/Standalone/lastusedsettings.cpp.orig	2024-09-12 07:10:41 UTC
+++ src/Standalone/lastusedsettings.cpp
@@ -17,7 +17,6 @@
 //  lastusedsettings.cpp -- template and derived ESC/I ESC/I-2 protocol commands
 
 #include <fstream>
-#define BOOST_NO_CXX11_RVALUE_REFERENCES 1
 #include <boost/any.hpp>
 #include <utils/PathUtils.h>
 #ifndef NO_QTMODE
