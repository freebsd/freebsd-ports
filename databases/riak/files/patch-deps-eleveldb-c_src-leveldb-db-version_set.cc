--- deps/eleveldb/c_src/leveldb/db/version_set.cc.orig	2013-08-29 23:03:04.000000000 +0200
+++ deps/eleveldb/c_src/leveldb/db/version_set.cc	2013-09-22 14:38:08.000000000 +0200
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
@@ -53,13 +55,13 @@
 
 // WARNING: m_OverlappedFiles flags need to match config::kNumOverlapFiles ... until unified
 {
-    {10485760,  262144000,  57671680,      209715200,             0,  300000000, true},
-    {10485760,   82914560,  57671680,      419430400,             0,  209715200, true},
-    {10485760,  104371840,  57671680,     1006632960,     200000000,  314572800, false},
-    {10485760,  125829120,  57671680,     4094304000,    3355443200,  419430400, false},
-    {10485760,  147286400,  57671680,    41943040000,   33554432000,  524288000, false},
-    {10485760,  188743680,  57671680,   419430400000,  335544320000,  629145600, false},
-    {10485760,  220200960,  57671680,  4194304000000, 3355443200000,  734003200, false}
+    {UINT64_C(10485760), UINT64_C(262144000), INT64_C(57671680), UINT64_C(    209715200), UINT64_C(            0), UINT64_C(300000000), true},
+    {UINT64_C(10485760), UINT64_C( 82914560), INT64_C(57671680), UINT64_C(    419430400), UINT64_C(            0), UINT64_C(209715200), true},
+    {UINT64_C(10485760), UINT64_C(104371840), INT64_C(57671680), UINT64_C(   1006632960), UINT64_C(    200000000), UINT64_C(314572800), false},
+    {UINT64_C(10485760), UINT64_C(125829120), INT64_C(57671680), UINT64_C(   4094304000), UINT64_C(   3355443200), UINT64_C(419430400), false},
+    {UINT64_C(10485760), UINT64_C(147286400), INT64_C(57671680), UINT64_C(  41943040000), UINT64_C(  33554432000), UINT64_C(524288000), false},
+    {UINT64_C(10485760), UINT64_C(188743680), INT64_C(57671680), UINT64_C( 419430400000), UINT64_C( 335544320000), UINT64_C(629145600), false},
+    {UINT64_C(10485760), UINT64_C(220200960), INT64_C(57671680), UINT64_C(4194304000000), UINT64_C(3355443200000), UINT64_C(734003200), false}
 };
