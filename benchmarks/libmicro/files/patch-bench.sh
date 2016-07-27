--- bench.sh.orig	2011-05-11 00:58:23 UTC
+++ bench.sh
@@ -65,7 +65,7 @@ mkdir -p $VDIR1 $VDIR2
 
 touch $IFILE
 
-ARCH=`arch -k`
+ARCH=`uname -p`
 
 # produce benchmark header for easier comparisons
 
@@ -83,6 +83,12 @@ if [ -f /proc/cpuinfo ]; then
 	p_type=`awk -F: '/model name/{print $2; exit}' /proc/cpuinfo`
 fi
 
+if [ F"`uname -s`" = F"FreeBSD" ] ; then
+	p_count=`sysctl -n hw.ncpu`
+	p_mhz=`sysctl -n hw.clockrate`
+	p_type=`sysctl -n hw.model`
+fi
+
 printf "!Libmicro_#:   %30s\n" $libmicro_version
 printf "!Options:      %30s\n" "$OPTS"
 printf "!Machine_name: %30s\n" $hostname
@@ -154,7 +160,6 @@ memset		$OPTS -N "memset_4k_uc" -s 4k   
 memset		$OPTS -N "memset_10k"	-s 10k	-I 600	 
 memset		$OPTS -N "memset_1m"	-s 1m	-I 200000
 memset		$OPTS -N "memset_10m"	-s 10m -I 2000000 
-memset		$OPTS -N "memsetP2_10m"	-s 10m -P 2 -I 2000000 
 
 memrand		$OPTS -N "memrand"	-s 128m -B 10000
 cachetocache	$OPTS -N "cachetocache" -s 100k -T 2 -I 200
