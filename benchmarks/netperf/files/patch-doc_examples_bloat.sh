--- doc/examples/bloat.sh.orig	2012-10-05 00:25:19 UTC
+++ doc/examples/bloat.sh
@@ -3,12 +3,7 @@
 # buffer bloat on latency.  We assume that netperf has been compiled
 # with demo-mode enabled via ./configure --enable-demo
 
-NETPERF=`which netperf`
-if [ $? -ne 0 ]
-then
-    echo "Unable to find a netperf binary."
-    exit -1
-fi
+NETPERF="%%PREFIX%%/bin/netperf"
 
 CHUNK=60
 
@@ -20,7 +15,7 @@ echo "Starting netperf TCP_RR at $RR_STA
 # in more accurate demo intervals once the STREAM test kicks-in, but a
 # somewhat lower transaction rate.  not unlike enabling histogram
 # mode.
-netperf -H $1 -l 7200 -t TCP_RR -D -0.5 -v 2 -- -r 1 2>&1 > netperf_rr.out &
+$NETPERF -H $1 -l 7200 -t TCP_RR -D -0.5 -v 2 -- -r 1 2>&1 > netperf_rr.out &
 
 # sleep CHUNK seconds
 sleep $CHUNK
@@ -29,7 +24,7 @@ sleep $CHUNK
 
 STREAM_START=`date +%s`
 echo "Starting netperf TCP_STREAM test at $STREAM_START" | tee -a bloat.log
-netperf -H $1 -l `expr $CHUNK \* 2` -t TCP_STREAM -D 0.25 -v 2 -- -m 1K 2>&1 > netperf_stream.out
+$NETPERF -H $1 -l `expr $CHUNK \* 2` -t TCP_STREAM -D 0.25 -v 2 -- -m 1K 2>&1 > netperf_stream.out
 STREAM_STOP=`date +%s`
 echo "Netperf TCP_STREAM test stopped at $STREAM_STOP" | tee -a bloat.log
 
