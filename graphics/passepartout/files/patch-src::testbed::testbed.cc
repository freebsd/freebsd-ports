--- src/testbed/testbed.cc.orig	Fri Oct 31 20:36:24 2003
+++ src/testbed/testbed.cc	Fri Oct 31 20:39:09 2003
@@ -1,6 +1,7 @@
 #include "testbed.hh"
 #include "util/warning.h"
 #include <glibmm/exception.h>	// Stupid glib!
+#include <algorithm>
 #include <functional>
 ///
 // Copyright (C) 2003, Fredrik Arnerup & Rasmus Kaj, See COPYING
@@ -53,7 +54,7 @@
     verbose.active = true;
     verbose << "Starting test run. " << TestCase::cases.size()
 	    << " case(s) to try." << std::endl;
-    for_each(TestCase::cases.begin(), TestCase::cases.end(),
+    std::for_each(TestCase::cases.begin(), TestCase::cases.end(),
 	     std::mem_fun(&TestCase::run));
     verbose << "Done running " << TestCase::cases.size() << " test case(s). "
 	    << TestCase::successes << " succeded, "
