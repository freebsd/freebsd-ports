--- src/libslic3r/SLA/SupportTree.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/SLA/SupportTree.cpp
@@ -16,9 +16,6 @@
 #include <libnest2d/optimizers/nlopt/genetic.hpp>
 #include <libnest2d/optimizers/nlopt/subplex.hpp>
 #include <boost/log/trivial.hpp>
-#include <tbb/parallel_for.h>
-#include <tbb/mutex.h>
-#include <tbb/spin_mutex.h>
 #include <libslic3r/I18N.hpp>
 
 //! macro used to mark string used at localization,
