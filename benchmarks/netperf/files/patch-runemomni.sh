--- doc/examples/runemomni.sh.orig	2011-07-28 22:35:06.000000000 +0200
+++ doc/examples/runemomni.sh	2015-10-19 15:22:10.484922000 +0200
@@ -1,6 +1,8 @@
 # a script to run a set of single-instance netperf tests
 # between two machines
 
+NETPERF="%%PREFIX%%/bin/netperf"
+
 # the length in seconds of each test iteration. the actual
 # run time will then be somewhere between that times min
 # and max iteration for confidence intervals
@@ -81,7 +83,7 @@
       fi
       for j in $set
       do 
-        netperf $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -m 64K;HDR="-P 0";
+        $NETPERF $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -m 64K;HDR="-P 0";
       done
     done
   fi
@@ -100,7 +102,7 @@
       fi
       for j in $set
       do
-        netperf $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -m 64K;HDR="-P 0";
+        $NETPERF $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -m 64K;HDR="-P 0";
       done
     done
   fi
@@ -119,7 +121,7 @@
       fi
       for j in $set
       do
-        netperf $HDR -T $i,$j -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV  -H $data -s 1M -S 1M -r 64K -b 12; HDR="-P 0";
+        $NETPERF $HDR -T $i,$j -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV  -H $data -s 1M -S 1M -r 64K -b 12; HDR="-P 0";
       done
     done
   fi
@@ -138,7 +140,7 @@
       fi
       for j in $set
       do
-        netperf $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -r 1; HDR="-P 0";
+        $NETPERF $HDR -T $i,$j -t omni -c -C -H $control_host -l $length $confidence -- $CSV -H $data -r 1; HDR="-P 0";
       done
     done
   fi
@@ -151,7 +153,7 @@
     do
       for req in $reqs; do
         for burst in $bursts; do
-          netperf $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -r $req -b $burst -D;HDR=-"P 0";
+          $NETPERF $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -r $req -b $burst -D;HDR=-"P 0";
         done
       done
     done
@@ -165,7 +167,7 @@
     do
        for req in $reqs; do
          for burst in $bursts; do
-           netperf $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -r $req -b $burst -T udp;HDR=-"P 0";
+           $NETPERF $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -r $req -b $burst -T udp;HDR=-"P 0";
          done
        done
     done
@@ -180,7 +182,7 @@
     for i in $netperf_CPUs
     do
       for req in $reqs; do
-        netperf $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -m $req -T udp;HDR=-"P 0";
+        $NETPERF $HDR -T $i -t omni -f m -c -C -H $control_host -l $length $confidence -- $CSV -H $data -s 1M -S 1M -m $req -T udp;HDR=-"P 0";
       done
     done
   fi
