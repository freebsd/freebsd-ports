--- src/runtime/SslWrap.cc.orig	2008-06-18 20:02:19.000000000 +0000
+++ src/runtime/SslWrap.cc	2008-06-18 20:03:13.000000000 +0000
@@ -6,6 +6,7 @@
 #include "base/polygraph.h"
 
 #include <stdlib.h>
+#include <assert.h>
 #include "xstd/h/iomanip.h"
 #include "xstd/Checksum.h"
 #include "xstd/Map.h"
@@ -18,6 +19,7 @@
 #include "pgl/SslWrapSym.h"
 #include "runtime/LogComment.h"
 #include "runtime/SslWrap.h"
+#include "xstd/Assert.h"
 
 static String TheUnknownFileName = "FILE_NAME_GOES_HERE";
 
