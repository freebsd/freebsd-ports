# HG changeset patch
# User Ehsan Akhgari <ehsan@mozilla.com>
# Date 1308517488 14400
# Node ID 284ebc48b2cb8e35dc04482ede700e717d8d214f
# Parent  cecc5adfc44068fb6f11b9baa78cb5fddc100b27
Bug 662961 - Silence the clang warnings issued because of alignment requirements increase when compiling jsstr.cpp; r=Waldo

--- deps/mozilla/js/src/jsstr.cpp.orig	2013-05-26 00:44:33.383765764 +1000
+++ deps/mozilla/js/src/jsstr.cpp	2013-05-26 00:46:35.842211859 +1000
@@ -3147,7 +3147,7 @@
  */
 #define R(c) {                                                                \
     BUILD_LENGTH_AND_FLAGS(1, JSString::FLAT | JSString::ATOMIZED),           \
-    { (jschar *)(((char *)(unitStringTable + (c))) +                          \
+    { (jschar *)(uintptr_t(unitStringTable + (c)) +                           \
       offsetof(JSString, inlineStorage)) },                                   \
     { {(c), 0x00} } }
 
@@ -3207,7 +3207,7 @@
  */
 #define R(c) {                                                                \
     BUILD_LENGTH_AND_FLAGS(2, JSString::FLAT | JSString::ATOMIZED),           \
-    { (jschar *)(((char *)(length2StringTable + (c))) +                       \
+    { (jschar *)(uintptr_t(length2StringTable + (c)) +                        \
       offsetof(JSString, inlineStorage)) },                                   \
     { {FROM_SMALL_CHAR((c) >> 6), FROM_SMALL_CHAR((c) & 0x3F), 0x00} } }
 
@@ -3240,7 +3240,7 @@
  */
 #define R(c) {                                                                \
     BUILD_LENGTH_AND_FLAGS(3, JSString::FLAT | JSString::ATOMIZED),           \
-    { (jschar *)(((char *)(hundredStringTable + ((c) - 100))) +               \
+    { (jschar *)(uintptr_t(hundredStringTable + ((c) - 100)) +                \
       offsetof(JSString, inlineStorage)) },                                   \
     { {((c) / 100) + '0', ((c) / 10 % 10) + '0', ((c) % 10) + '0', 0x00} } }
 
