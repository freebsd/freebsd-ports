--- doc/examples/runemomniaggdemo.sh.orig	2013-05-10 18:14:25 UTC
+++ doc/examples/runemomniaggdemo.sh
@@ -138,7 +138,7 @@ then
 fi
 
 # allow the netperf binary to be used to be overridden 
-NETPERF=${NETPERF:="netperf"}
+NETPERF="%%PREFIX%%/bin/netperf"
 
 if [ $NUM_REMOTE_HOSTS -lt 2 ]
 then
