--- pgms/cleanup.sh.orig	Sun Dec 19 01:42:45 2004
+++ pgms/cleanup.sh	Sun Dec 19 01:43:00 2004
@@ -107,8 +107,8 @@
 	;;
     
     -r) # reason for failure
-	echo $1
-	echo $1 >>$LOGFILE
+	echo -e $1
+	echo -e $1 >>$LOGFILE
 	shift
 	;;
 
