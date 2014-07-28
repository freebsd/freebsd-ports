--- sdts++/builder/sb_Accessor.cpp.orig	2003-06-11 00:51:40.000000000 +0400
+++ sdts++/builder/sb_Accessor.cpp	2012-03-11 20:18:18.000000000 +0300
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
@@ -155,27 +162,27 @@
 
 
 
-static const char* module_mnemonics_[] =
-{ 
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
-}; // module_mnemonics
+static const char* module_mnemonics_[] =
+{ 
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
+}; // module_mnemonics
 
 
 
