--- src/Standalone/defaultsettings.cpp.orig	2024-09-12 07:10:39 UTC
+++ src/Standalone/defaultsettings.cpp
@@ -18,7 +18,6 @@
 
 #include "defaultsettings.h"
 #include <fstream>
-#define BOOST_NO_CXX11_RVALUE_REFERENCES 1
 #include <boost/any.hpp>
 #include <utils/PathUtils.h>
 #if !(defined(NO_QTMODE) || defined(BUILDSANE))
