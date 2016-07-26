--- test/run_tests.sh.orig	2013-05-09 15:20:50 UTC
+++ test/run_tests.sh
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
