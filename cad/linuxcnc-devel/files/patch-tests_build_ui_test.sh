--- tests/build/ui/test.sh.orig	2016-06-25 02:19:12 UTC
+++ tests/build/ui/test.sh
@@ -1,6 +1,7 @@
 #!/bin/sh
 set -x
-g++ -I $EMC2_HOME/include \
+c++ -I $EMC2_HOME/include \
+    -I /usr/local/include \
     nml-position-logger.cc \
     -L $EMC2_HOME/lib -lnml -llinuxcnc \
     -o /dev/null
