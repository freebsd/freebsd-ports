--- utils/Value.hpp.orig
+++ utils/Value.hpp
@@ -15,7 +15,8 @@
 #ifndef _Value_hpp_
 #define _Value_hpp_
 
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
 #include <string>
 
 #include <Trace.hpp>
@@ -38,8 +39,8 @@
     Value( string s):
       _valType(String), 
       _valString(s),
-      _valInt( atoi(s.c_str())),
-      _valFloat( (float)atof( s.c_str())),
+      _valInt( (int)strtol( s.c_str(), (char **)NULL, 10)),
+      _valFloat( (float)strtod( s.c_str(), (char **)NULL)),
       _valBool( stringToBool(s))
     { 
         XTRACE();
