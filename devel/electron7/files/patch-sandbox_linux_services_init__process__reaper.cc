--- sandbox/linux/services/init_process_reaper.cc.orig	2019-12-12 12:39:56 UTC
+++ sandbox/linux/services/init_process_reaper.cc
@@ -1,6 +1,7 @@
 // Copyright 2013 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "sandbox/linux/services/init_process_reaper.h"
 
@@ -100,3 +101,4 @@ bool CreateInitProcessReaper(base::OnceClosure post_fo
 }
 
 }  // namespace sandbox.
+#endif
