--- util/thread_local.cc.orig	2015-02-10 05:49:22.000000000 +0800
+++ util/thread_local.cc	2015-02-21 15:54:52.950817216 +0800
@@ -7,6 +7,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file. See the AUTHORS file for names of contributors.
 
+#include <cstdlib>
+
 #include "util/thread_local.h"
 #include "util/mutexlock.h"
 #include "port/likely.h"
