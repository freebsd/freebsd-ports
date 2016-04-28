--- util/thread_posix.cc.orig	2016-03-25 19:09:20 UTC
+++ util/thread_posix.cc
@@ -7,6 +7,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file. See the AUTHORS file for names of contributors.
 
+#include <cstdlib>
+
 #include "util/thread_posix.h"
 #include <atomic>
 #include <unistd.h>
