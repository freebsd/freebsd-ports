
$FreeBSD$

--- bin/runide.sh.orig	Mon Jun  2 11:23:48 2003
+++ bin/runide.sh	Mon Jun  2 11:26:50 2003
@@ -157,7 +157,7 @@
         
         -hotspot|-client|-server|-classic|-native|-green) thread_flag=$1;;
         -J-hotspot|-J-client|-J-server|-J-classic|-J-native|-J-green) thread_flag=`expr $1 : '-J\(.*\)'`;;
-        -J*) jopt=`expr "$1" : '-J\(.*\)'`; jargs="$jargs \"$jopt\"";;
+        -J*) jopt=`expr -- "$1" : '-J\(.*\)'`; jargs="$jargs \"$jopt\"";;
         *) args="$args \"$1\"" ;;
     esac
     shift
@@ -182,25 +182,6 @@
 parse_args "$@"
 
 #
-# check JDK
-#
-
-if [ -z "$jdkhome" ] ; then
-    echo "Cannot find JDK. Please set the JDK_HOME environment variable to point"
-    echo "to your JDK installation directory, or use the -jdkhome switch"
-    echo ""
-    exit 1
-fi
-
-if [ ! -x "${jdkhome}/bin/java" ] ; then
-    echo "Cannot find JDK at ${jdkhome}. Please set the JDK_HOME"
-    echo "environment variable to point to your JDK installation directory,"
-    echo "or use the -jdkhome switch"
-    echo ""
-    exit 1
-fi
-
-#
 # open file?
 #
 
@@ -212,7 +193,7 @@
     if [ ! -z "$port" ] ; then
         args="$args -port $port"
     fi
-    eval "\"$jdkhome/bin/java\"" -classpath "\"${idehome}/modules/utilities.jar\"" $openfile_class $args "\"$openfile\""
+    eval javavm -classpath "\"${idehome}/modules/utilities.jar\"" $openfile_class $args "\"$openfile\""
     rc=$?
     
     if [ $rc -eq 0 -o $rc -eq 1 ] ; then
@@ -267,7 +248,7 @@
 }
 
 do_run_updater() {
-    eval "\"$jdkhome/bin/java\"" $thread_flag -classpath "\"${updatercp}\"" $jargs $updater_class
+    eval javavm $thread_flag -classpath "\"${updatercp}\"" $jargs $updater_class
 }
 
 look_for_pre_runs() {
@@ -406,7 +387,7 @@
         openfile=""
     fi
     
-    eval "\"${jdkhome}/bin/java\"" -Djdk.home="\"${jdkhome}\"" $thread_flag -classpath "\"$cp\"" \
+    eval javavm -Djdk.home="\"${jdkhome}\"" $thread_flag -classpath "\"$cp\"" \
         -Dnetbeans.osenv="${nbenvfile}" \
         ${openfile_prop} \
         $jargs $ide_class $args
