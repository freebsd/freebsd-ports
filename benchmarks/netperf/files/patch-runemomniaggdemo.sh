--- doc/examples/runemomniaggdemo.sh.orig	2013-05-10 20:14:25.000000000 +0200
+++ doc/examples/runemomniaggdemo.sh	2015-10-19 15:37:46.597952000 +0200
@@ -138,7 +138,7 @@
 fi
 
 # allow the netperf binary to be used to be overridden 
-NETPERF=${NETPERF:="netperf"}
+NETPERF="%%PREFIX%%/bin/netperf"
 
 if [ $NUM_REMOTE_HOSTS -lt 2 ]
 then
