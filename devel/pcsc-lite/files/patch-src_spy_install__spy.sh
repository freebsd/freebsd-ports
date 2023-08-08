--- src/spy/install_spy.sh.orig	2020-08-05 11:01:32 UTC
+++ src/spy/install_spy.sh
@@ -5,7 +5,7 @@ set -e
 
 # ldconfig --print-cache will return something like
 # libpcsclite.so.1 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libpcsclite.so.1
-DIR=$(ldconfig --print-cache | grep libpcsclite.so.1)
+DIR=$(ldconfig -r | grep libpcsclite.so.1)
 
 # get the right part only: /usr/lib/x86_64-linux-gnu/libpcsclite.so.1
 DIR=$(echo $DIR | cut -d'=' -f2 | cut -d' ' -f2)
@@ -14,7 +14,7 @@ DIR=$(dirname $DIR)
 DIR=$(dirname $DIR)
 
 # find the spying library
-SPY=$(ldconfig --print-cache | grep libpcscspy.so)
+SPY=$(ldconfig -r | grep libpcscspy.so)
 SPY=$(echo $SPY | cut -d'=' -f2 | cut -d' ' -f2)
 
 echo "Using directory:" $DIR
