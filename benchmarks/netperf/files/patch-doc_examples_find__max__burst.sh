--- doc/examples/find_max_burst.sh.orig	2017-09-21 17:32:54 UTC
+++ doc/examples/find_max_burst.sh
@@ -6,7 +6,7 @@
 LAST_TPS=0
 BURST=1
 LAST_BURST=0
-NETPERF=${NETPERF:="netperf"}
+NETPERF="%%PREFIX%%/bin/netperf"
 
 TMP_TPS=`$NETPERF -t UDP_RR -P 0 -H $1 -- -b $BURST -D -o throughput -e 1 -s 1M -S 1M`
 
