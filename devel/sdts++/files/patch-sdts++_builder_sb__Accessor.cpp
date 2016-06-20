--- sdts++/builder/sb_Accessor.cpp.orig	2016-06-20 14:59:02 UTC
+++ sdts++/builder/sb_Accessor.cpp
@@ -26,6 +26,13 @@
 #include <cctype>
 #include <cstring>
 
+#ifdef __FreeBSD__
+#  include <osreldate.h>
+#  if __FreeBSD_version < 500035
+#    include <stlport/iosfwd>
+#  endif
+#endif
+namespace std { using ::mbstate_t; }
 #include <boost/smart_ptr.hpp>
 #include <boost/filesystem/path.hpp>
 #include <boost/filesystem/operations.hpp>
@@ -157,24 +164,24 @@ sb_Accessor::~sb_Accessor( )
 
 static const char* module_mnemonics_[] =
 { 
-  {"CATS"},
-  {"CATD"},
-  {"DDOM"},
-  {"DDSH"},
-  {"MDOM"},
-  {"MDEF"},
-  {"DQHL"},
-  {"DQPA"},
-  {"DQAA"},
-  {"DQLC"},
-  {"DQCG"},
-  {"IDEN"},
-  {"IREF"},
-  {"LDEF"},
-  {"RSDF"},
-  {"STAT"},
-  {"XREF"},
-  {""}
+  "CATS",
+  "CATD",
+  "DDOM",
+  "DDSH",
+  "MDOM",
+  "MDEF",
+  "DQHL",
+  "DQPA",
+  "DQAA",
+  "DQLC",
+  "DQCG",
+  "IDEN",
+  "IREF",
+  "LDEF",
+  "RSDF",
+  "STAT",
+  "XREF",
+  ""
 }; // module_mnemonics
 
 
