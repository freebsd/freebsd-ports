--- src/util/cmdline.cc.orig	Sat Jan 17 23:49:30 2004
+++ src/util/cmdline.cc	Sat Jan 17 23:50:03 2004
@@ -2,6 +2,7 @@
 // Copyright (C) 2003, 2004, Fredrik Arnerup & Rasmus Kaj, See COPYING
 ///
 #include "cmdline.h"
+#include <algorithm>
 
 CmdLine::CmdLine(int argc, char **argv) : seen_double_dash(false)
 {
