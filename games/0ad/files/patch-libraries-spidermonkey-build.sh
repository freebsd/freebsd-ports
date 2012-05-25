--- libraries/spidermonkey/build.sh.orig	2012-01-31 01:06:56.000000000 +0100
+++ libraries/spidermonkey/build.sh	2012-05-03 15:49:34.640969629 +0200
@@ -49,6 +49,11 @@
 
 cd js-1.8.5/js/src
 
+cp jsnativestack.cpp jsnativestack.cpp.orig
+sed 's/#  include <pthread_np.h>/#pragma GCC visibility push(default)\
+#include <pthread_np.h>\
+#pragma GCC visibility pop/' jsnativestack.cpp.orig >jsnativestack.cpp
+
 # We want separate debug/release versions of the library, so we have to change
 # the LIBRARY_NAME for each build.
 # (We use perl instead of sed so that it works with MozillaBuild on Windows,
