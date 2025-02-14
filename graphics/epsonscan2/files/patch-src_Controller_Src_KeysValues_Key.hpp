--- src/Controller/Src/KeysValues/Key.hpp.orig	2024-09-12 07:10:34 UTC
+++ src/Controller/Src/KeysValues/Key.hpp
@@ -21,7 +21,6 @@
 #include "EpsonScan2.h"
 #include "KeyDataProvider.hpp"
 #include <ESCommonTypedef.h>
-#define BOOST_NO_CXX11_RVALUE_REFERENCES 1
 #include <boost/any.hpp>
 #include <memory>
 namespace epsonscan {
