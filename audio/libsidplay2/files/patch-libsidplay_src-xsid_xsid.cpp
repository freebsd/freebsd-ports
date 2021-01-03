--- libsidplay/src/xsid/xsid.cpp.orig	2004-06-14 20:08:02 UTC
+++ libsidplay/src/xsid/xsid.cpp
@@ -96,8 +96,8 @@ const int8_t XSID::sampleConvertTable[16] =
 */
 const int8_t XSID::sampleConvertTable[16] =
 {
-    '\x80', '\x94', '\xa9', '\xbc', '\xce', '\xe1', '\xf2', '\x03',
-    '\x1b', '\x2a', '\x3b', '\x49', '\x58', '\x66', '\x73', '\x7f'
+    (int8_t)'\x80', (int8_t)'\x94', (int8_t)'\xa9', (int8_t)'\xbc', (int8_t)'\xce', (int8_t)'\xe1', (int8_t)'\xf2', (int8_t)'\x03',
+    (int8_t)'\x1b', (int8_t)'\x2a', (int8_t)'\x3b', (int8_t)'\x49', (int8_t)'\x58', (int8_t)'\x66', (int8_t)'\x73', (int8_t)'\x7f'
 };
 
 const char *XSID::credit =
