--- src/dtlv.h.orig	2026-03-01 22:54:30 UTC
+++ src/dtlv.h
@@ -12,8 +12,8 @@
  *  This code is released under Eclipse Public License 2.0.
  */
 
-#include "lmdb/libraries/liblmdb/dlmdb.h"
-#include "usearch/c/usearch.h"
+#include <dlmdb.h>
+#include <usearch/usearch.h>
 
 #ifdef __cplusplus
 extern "C" {
