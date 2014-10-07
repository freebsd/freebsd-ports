--- fem/acx_elmer.m4.orig	2014-09-06 21:01:43.000000000 -0500
+++ fem/acx_elmer.m4	2014-09-06 21:02:07.000000000 -0500
@@ -851,7 +851,6 @@
 dnl run it
 dnl printf "running: $CXX $acx_cxx_verbose_flag test.cpp 2>&1 |grep -e ' -l'\n"
 acx_cxx_verbose_out=`$CXX $acx_cxx_verbose_flag test.cpp 2>&1 |grep -e ' -l'`
-acx_cxx_verbose_out=${acx_cxx_verbose_out//\"/
 acx_cxx_libs=""
 
 dnl get only the -l -L -R flags
