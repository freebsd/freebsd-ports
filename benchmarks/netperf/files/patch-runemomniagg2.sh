--- doc/examples/runemomniagg2.sh.orig	2011-07-28 20:37:22.000000000 +0200
+++ doc/examples/runemomniagg2.sh	2015-10-19 15:35:43.704236000 +0200
@@ -1,4 +1,7 @@
 #set -x
+
+NETPERF="%%PREFIX%%/bin/netperf"
+
 # edit and add to this array as necessary
 # the hosts you will use should be contiguous
 # starting at index zero
@@ -84,11 +87,11 @@
   echo TCP_STREAM
   for i in $concurrent_sessions; do
     j=0; 
-    NETUUID=`netperf -t uuid`;
+    NETUUID=`$NETPERF -t uuid`;
     echo $i concurrent streams id $NETUUID;
     while [ $j -lt $i ]; do 
       client=`expr $j % $num_cli` ;
-      netperf $HDR -t omni -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV -H ${remote_hosts[$client]} $socket_sizes -m 64K -u $NETUUID & HDR="-P 0";
+      $NETPERF $HDR -t omni -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV -H ${remote_hosts[$client]} $socket_sizes -m 64K -u $NETUUID & HDR="-P 0";
       j=`expr $j + 1`;
     done;
     wait;
@@ -99,11 +102,11 @@
   echo TCP_MAERTS
   for i in $concurrent_sessions; do
     j=0;
-    NETUUID=`netperf -t uuid`;
+    NETUUID=`$NETPERF -t uuid`;
     echo $i concurrent streams id $NETUUID;
     while [ $j -lt $i ]; do
       client=`expr $j % $num_cli` ;
-      netperf $HDR -t omni -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV -H ${remote_hosts[$client]} $socket_sizes -M ,64K -u $NETUUID & HDR="-P 0";
+      $NETPERF $HDR -t omni -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV -H ${remote_hosts[$client]} $socket_sizes -M ,64K -u $NETUUID & HDR="-P 0";
       j=`expr $j + 1`;
     done;
     wait;
@@ -115,11 +118,11 @@
   HDR="-P 1"
   for i in $concurrent_sessions;
     do j=0;
-    NETUUID=`netperf -t uuid`;
+    NETUUID=`$NETPERF -t uuid`;
     echo $i concurrent streams id $NETUUID;
     while [ $j -lt $i ]; do
       client=`expr $j % $num_cli` ;
-      netperf $HDR  -t omni -f m -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV  -H ${remote_hosts[$client]} -s 1M -S 1M -r 64K -b 12 -u $NETUUID & HDR="-P 0";
+      $NETPERF $HDR  -t omni -f m -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV  -H ${remote_hosts[$client]} -s 1M -S 1M -r 64K -b 12 -u $NETUUID & HDR="-P 0";
       j=`expr $j + 1`;
     done;
     wait;
@@ -130,14 +133,14 @@
   echo TCP_RR aggregates
   HDR="-P 1"
   for i in $concurrent_sessions; do
-    NETUUID=`netperf -t uuid`;
+    NETUUID=`$NETPERF -t uuid`;
     echo $i concurrent streams id $NETUUID;
     for b in $burst_sizes; do
       echo burst of $b;
       j=0;
       while [ $j -lt $i ]; do
         client=`expr $j % $num_cli` ;
-        netperf $HDR  -t omni -f x -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV  -H ${remote_hosts[$client]} -r 1 -b $b -D -u $NETUUID & HDR="-P 0";
+        $NETPERF $HDR  -t omni -f x -c -C -H ${remote_hosts[$client]} -l $length $confidence -- $CSV  -H ${remote_hosts[$client]} -r 1 -b $b -D -u $NETUUID & HDR="-P 0";
         j=`expr $j + 1`;
       done;
       wait;
