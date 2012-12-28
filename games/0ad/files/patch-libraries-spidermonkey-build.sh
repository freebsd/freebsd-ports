--- libraries/spidermonkey/build.sh.orig	2012-06-11 00:39:26.000000000 +0200
+++ libraries/spidermonkey/build.sh	2012-12-18 10:58:11.343785532 +0100
@@ -53,6 +53,14 @@
 
 cd js-1.8.5/js/src
 
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
