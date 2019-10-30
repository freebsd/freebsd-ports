--- sys-uuid.cc.orig	2019-06-23 11:41:41 UTC
+++ sys-uuid.cc
@@ -17,6 +17,8 @@
 #include "autoconf.hh"
 #include "system.hh"
 
+#include <cstring>
+
 #if WIN32
 
 #include <cassert>
