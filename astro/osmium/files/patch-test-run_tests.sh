--- test/run_tests.sh.orig	2013-05-09 19:20:50.000000000 +0400
+++ test/run_tests.sh	2013-05-23 00:01:42.140354335 +0400
@@ -10,8 +10,10 @@
 
 set -e
 
-CXX="g++"
-CXXFLAGS="-g -Wall -Wextra -Wredundant-decls -Wdisabled-optimization -pedantic -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo -Wno-long-long"
+if [ -z "$CXX" ]; then
+	CXX="g++"
+fi
+CXXFLAGS="$CXXFLAGS -g -Wall -Wextra -Wredundant-decls -Wdisabled-optimization -pedantic -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo -Wno-long-long"
 COMPILE="$CXX -I../include -I. $CXXFLAGS -o tests"
 
 if [ "x$1" = "x-v" ]; then
