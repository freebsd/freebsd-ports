$FreeBSD$

--- ../src/solaris/bin/java_wrapper_bsd.sh	1 Oct 2001 11:44:43 -0000	1.4
+++ ../src/solaris/bin/java_wrapper_bsd.sh	17 Apr 2003 15:07:23 -0000
@@ -71,37 +71,56 @@
 # Select vm type (if classic vm, also select thread type).
 unset vmtype
 unset ttype
+unset vmopt
 DEFAULT_THREADS_FLAG=green
-if [ "x$1" = "x-hotspot" ]; then
-    vmtype=hotspot
+if [ "x$1" = "x-client" ]; then
+    vmtype=client
     ttype=native_threads
+    vmopt=-$vmtype
     shift 1
 else
     if [ "x$1" = "x-classic" ]; then
 	vmtype=classic
-	ttype=${DEFAULT_THREADS_FLAG}_threads
+	if [ ${THREADS_FLAG:-${DEFAULT_THREADS_FLAG}} = native ]; then 
+	   ttype=native_threads
+	else
+	   ttype=green_threads
+	fi
+	vmopt=-$vmtype
 	shift 1
     else
 	if [ "x$1" = "x-green" ]; then
 	    vmtype=classic
 	    ttype=green_threads
+	    vmopt=-$vmtype
 	    shift 1
 	else
 	    if [ "x$1" = "x-native" ]; then
 		vmtype=classic
 		ttype=native_threads
+		vmopt=-$vmtype
 		shift 1
 	    else 
-		if [ -d ${jre}/lib/${proc}/hotspot ]; then
-		    vmtype=hotspot
+		if [ "x$1" = "x-server" ]; then
+		    vmtype=server
 		    ttype=native_threads
-		else
-		    vmtype=classic
-		    if [ ${THREADS_FLAG:-${DEFAULT_THREADS_FLAG}} = native ]
-		    then 
+		    vmopt=-$vmtype
+		    shift 1
+		else 
+		    if [ "x$1" = "x-hotspot" ]; then
+			vmtype=client
 			ttype=native_threads
-		    else
-			ttype=green_threads
+			vmopt=-$vmtype
+			shift 1
+		    else     
+			vmtype=classic
+			if [ ${THREADS_FLAG:-${DEFAULT_THREADS_FLAG}} = native ]
+			then 
+			    ttype=native_threads
+			else
+			    ttype=green_threads
+			fi
+			vmopt=-$vmtype
 		    fi
 		fi
 	    fi
@@ -141,7 +160,7 @@
 # Run.
 if [ -x "$prog" ]
 then
-    exec $DEBUG_PROG "$prog" "$@"
+    exec $DEBUG_PROG "$prog" "$vmopt" "$@"
 else
     echo >&2 "$progname was not found in ${prog}"
     exit 1
