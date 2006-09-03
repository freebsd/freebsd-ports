Index: src/scim_anthy_key2kana.cpp
diff -u src/scim_anthy_key2kana.cpp.orig src/scim_anthy_key2kana.cpp
--- src/scim_anthy_key2kana.cpp.orig	Tue Jul 11 11:22:08 2006
+++ src/scim_anthy_key2kana.cpp	Mon Sep  4 01:45:58 2006
@@ -23,6 +23,8 @@
 #include "scim_anthy_imengine.h"
 #include "scim_anthy_utils.h"
 
+#include <wctype.h>
+
 using namespace scim_anthy;
 
 Key2KanaConvertor::Key2KanaConvertor (AnthyInstance    & anthy,
