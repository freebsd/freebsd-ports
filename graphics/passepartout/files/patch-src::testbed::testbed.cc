--- src/testbed/testbed.cc.orig	Sat Jan 17 22:58:16 2004
+++ src/testbed/testbed.cc	Sat Jan 17 22:42:18 2004
@@ -1,6 +1,7 @@
 #include "testbed.hh"
 #include "util/warning.h"
 #include <glibmm/exception.h>	// Stupid glib!
+#include <algorithm>
 #include <functional>
 ///
 // Copyright (C) 2003, 2004, Fredrik Arnerup & Rasmus Kaj, See COPYING
@@ -53,7 +54,7 @@
     verbose.active = true;
     verbose << "Starting test run. " << TestCase::cases.size()
 	    << " case(s) to try." << std::endl;
-    for_each(TestCase::cases.begin(), TestCase::cases.end(),
+    std::for_each(TestCase::cases.begin(), TestCase::cases.end(),
 	     std::mem_fun(&TestCase::run));
     verbose << "Done running " << TestCase::cases.size() << " test case(s). "
 	    << TestCase::successes << " succeded, "
