--- kernel/fhdl_stream.cc.orig	2006-01-12 08:05:01.000000000 +0000
+++ kernel/fhdl_stream.cc
@@ -2,6 +2,7 @@
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <cstring>
 #include <sstream>
 #include <assert.h>
 #include <freehdl/kernel-error.hh>
