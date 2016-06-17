--- pgms/cleanup.sh.orig	1997-09-13 02:01:19 UTC
+++ pgms/cleanup.sh
@@ -107,8 +107,8 @@ do
 	;;
     
     -r) # reason for failure
-	echo $1
-	echo $1 >>$LOGFILE
+	echo -e $1
+	echo -e $1 >>$LOGFILE
 	shift
 	;;
 
