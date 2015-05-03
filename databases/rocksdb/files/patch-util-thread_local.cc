--- util/thread_local.cc.orig	2015-03-25 21:40:41 UTC
+++ util/thread_local.cc
@@ -7,6 +7,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file. See the AUTHORS file for names of contributors.
 
+#include <cstdlib>
+
 #include "util/thread_local.h"
 #include "util/mutexlock.h"
 #include "port/likely.h"
