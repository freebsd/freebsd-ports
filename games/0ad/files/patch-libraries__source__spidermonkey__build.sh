--- libraries/source/spidermonkey/build.sh.orig	2014-09-24 08:29:20 UTC
+++ libraries/source/spidermonkey/build.sh
@@ -66,6 +66,14 @@
 
 cd mozjs24/js/src
 
+cp jsnativestack.cpp jsnativestack.cpp.orig
+sed 's/#  include <pthread_np.h>/#pragma GCC visibility push(default)\
+#include <pthread_np.h>\
+#pragma GCC visibility pop/' jsnativestack.cpp.orig >jsnativestack.cpp
+
+cp configure configure.orig
+sed 's/"$ac_cv_have_visibility_class_bug" = "no"; then/"$ac_cv_have_visibility_class_bug" = "no" -a "$OS_ARCH" != "FreeBSD" ; then/' configure.orig >configure
+
 # We want separate debug/release versions of the library, so we have to change
 # the LIBRARY_NAME for each build.
 # (We use perl instead of sed so that it works with MozillaBuild on Windows,
