--- ddupcron.sh.orig	Mon Oct 23 02:11:48 2000
+++ ddupcron.sh	Thu Nov  2 14:16:39 2000
@@ -2,19 +2,23 @@
 
 # Define the host to be updated as 1st arguement to script
 if [ -z $1 ]; then
-	echo "Usage: ddupcron.sh hostname"
+	echo "Usage: ddupcron.sh hostname [interface]"
 	exit
 else
 	HOST=$1
 fi
 # Define interface to grep address from
-IFACE="eth0"
+if [ -z $2 ]; then
+	IFACE=fxp0
+else
+	IFACE=$2
+fi
 IFCHECK=$(/sbin/ifconfig $IFACE|grep ask|awk '{print $2}'|cut -d ':' -f2)
 # Define where we should store last IP
 IPFILE="/tmp/ddupip"
 IPCHECK=$(cat $IPFILE)
 # Define path to ddup and ddup arguments (except --host)
-DDUP_PATH="/home/ddup/ddup"
+DDUP_PATH="!!PREFIX!!/sbin/ddup"
 DDUP_ARGS="--debug"
 
 
