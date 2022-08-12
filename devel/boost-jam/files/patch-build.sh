--- build.sh.orig	2022-07-07 02:17:31 UTC
+++ build.sh
@@ -497,6 +497,7 @@ modules/set.cpp \
     else B2_CXXFLAGS="${B2_CXXFLAGS_RELEASE} -DNDEBUG"
     fi
     ( B2_VERBOSE_OPT=${TRUE} echo_run ${B2_CXX} ${B2_CXXFLAGS} ${B2_SOURCES} -o b2 )
+    ( B2_VERBOSE_OPT=${TRUE} echo_run cp b2 bjam )
 }
 
 if test_true ${B2_VERBOSE_OPT} ; then
