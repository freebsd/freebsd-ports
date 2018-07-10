--- deps/eleveldb/c_src/leveldb/db/version_set.cc.orig	2014-12-04 17:57:13 UTC
+++ deps/eleveldb/c_src/leveldb/db/version_set.cc
@@ -2,10 +2,12 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file. See the AUTHORS file for names of contributors.
 
+#define __STDC_CONSTANT_MACROS
 #include "db/version_set.h"
 
 #include <algorithm>
 #include <stdio.h>
+#include <stdint.h>
 #include "db/filename.h"
 #include "db/log_reader.h"
 #include "db/log_writer.h"
@@ -56,13 +58,13 @@ static struct
 
 // WARNING: m_OverlappedFiles flags need to match config::kNumOverlapFiles ... until unified
 {
-    {10485760,  262144000,  57671680,      209715200,                0,     300000000, true},
-    {10485760,   82914560,  57671680,      419430400,                0,     209715200, true},
-    {10485760,  314572800,  57671680,     1006632960,        200000000,     314572800, false},
-    {10485760,  419430400,  57671680,     4094304000ULL,    3355443200ULL,  419430400, false},
-    {10485760,  524288000,  57671680,    41943040000ULL,   33554432000ULL,  524288000, false},
-    {10485760,  629145600,  57671680,   419430400000ULL,  335544320000ULL,  629145600, false},
-    {10485760,  734003200,  57671680,  4194304000000ULL, 3355443200000ULL,  734003200, false}
+    {UINT64_C(10485760), UINT64_C(262144000), INT64_C(57671680), UINT64_C(    209715200), UINT64_C(            0), UINT64_C(300000000), true},
+    {UINT64_C(10485760), UINT64_C( 82914560), INT64_C(57671680), UINT64_C(    419430400), UINT64_C(            0), UINT64_C(209715200), true},
+    {UINT64_C(10485760), UINT64_C(314572800), INT64_C(57671680), UINT64_C(   1006632960), UINT64_C(    200000000), UINT64_C(314572800), false},
+    {UINT64_C(10485760), UINT64_C(419430400), INT64_C(57671680), UINT64_C(   4094304000), UINT64_C(   3355443200), UINT64_C(419430400), false},
+    {UINT64_C(10485760), UINT64_C(524288000), INT64_C(57671680), UINT64_C(  41943040000), UINT64_C(  33554432000), UINT64_C(524288000), false},
+    {UINT64_C(10485760), UINT64_C(629145600), INT64_C(57671680), UINT64_C( 419430400000), UINT64_C( 335544320000), UINT64_C(629145600), false},
+    {UINT64_C(10485760), UINT64_C(734003200), INT64_C(57671680), UINT64_C(4194304000000), UINT64_C(3355443200000), UINT64_C(734003200), false}
 };
 
 /// ULL above needed to compile on OSX 10.7.3
