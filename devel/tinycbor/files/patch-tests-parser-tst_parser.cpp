--- tests/parser/tst_parser.cpp.orig	2026-02-18 17:25:07 UTC
+++ tests/parser/tst_parser.cpp
@@ -22,7 +22,9 @@
 **
 ****************************************************************************/
 
+#if !defined(__FreeBSD__)
 #define _XOPEN_SOURCE 700
+#endif
 #define  _DARWIN_C_SOURCE 1         /* need MAP_ANON */
 #include <QtTest>
 #include "cbor.h"
