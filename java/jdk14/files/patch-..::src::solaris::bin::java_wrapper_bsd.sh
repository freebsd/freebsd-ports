
$FreeBSD$

--- ../src/solaris/bin/java_wrapper_bsd.sh.orig	Mon Sep 10 12:20:57 2001
+++ ../src/solaris/bin/java_wrapper_bsd.sh	Mon Sep 10 14:23:56 2001
@@ -121,13 +121,17 @@
     export _JVM_THREADS_TYPE
 fi
 
-# Set LD_LIBRARY_PATH for hotspot VM.
-#j=`$jre/bin/realpath $jre`
-ld="${jre}/lib/${proc}/${ttype}:${jre}/lib/${proc}/${vmtype}:${jre}/lib/${proc}"
+# If jre is in a jre subdir, include parent dir libraries in lib path.  This
+# needs to be cleaned up because -Xrun libraries are the ones that need it.
+if [ "${jre}" = "${JREHOME}" ]; then
+    JAVA_LIBRARY_PATH=":${jre}/../lib/${proc}"
+fi
+# Set LD_LIBRARY_PATH for thread type, VM type and standard native libraries.
+JAVA_LIBRARY_PATH="${jre}/lib/${proc}/${ttype}:${jre}/lib/${proc}/${vmtype}:${jre}/lib/${proc}${JAVA_LIBRARY_PATH}"
 if [ -z "$LD_LIBRARY_PATH" ]; then
-    LD_LIBRARY_PATH="$ld"
+    LD_LIBRARY_PATH="${JAVA_LIBRARY_PATH}"
 else
-    LD_LIBRARY_PATH="$ld:$LD_LIBRARY_PATH"
+    LD_LIBRARY_PATH="${JAVA_LIBRARY_PATH}:$LD_LIBRARY_PATH"
 fi
 export LD_LIBRARY_PATH
 
