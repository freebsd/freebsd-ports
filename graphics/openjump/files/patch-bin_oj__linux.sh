--- bin/oj_linux.sh	2026-04-03 21:13:54.084260000 +0200
+++ bin/oj_linux.sh	2026-04-03 21:19:43.098211000 +0200
@@ -4,9 +4,11 @@
 ## if unset defaults to
 ##   JUMP_HOME (oj app folder) if writable or $HOME/.openjump (user home)
 #JUMP_SETTINGS="/tmp/foobar"
+JUMP_SETTINGS="$HOME/.openjump"
 
 ## uncomment and put the path to your jre here
 #JAVA_HOME="/home/ed/jre1.6.0_21"
+JAVA_HOME=${JAVA_HOME}
 
 ## uncomment and change your memory configuration here 
 ## Xms is initial size, Xmx is maximum size
@@ -282,7 +282,7 @@
   echo ---GDAL_DATA---
   echo $GDAL_DATA
 
-  NATIVE_PATH="$NATIVE_PATH:/usr/local/opt/sqlite/lib/:/usr/local/lib/"
+  NATIVE_PATH="$NATIVE_PATH:/usr/local/lib/"
   CLASSPATH="/usr/local/lib/gdal.jar:$CLASSPATH"
 
   ## add lib/native/[arch/] to lib path
@@ -304,7 +304,7 @@
   echo ---GDAL_DATA---
   echo $GDAL_DATA
 
-  NATIVE_PATH="$GDALPATH:$GDALPATH/lib:$GDALPATH/java:$NATIVE_PATH:/usr/lib/jni"
+  NATIVE_PATH="$GDALPATH:$GDALPATH/lib:$GDALPATH/java:$NATIVE_PATH:/usr/lib/jni:/usr/local/lib:${PREFIX}/lib"
   CLASSPATH="$GDALPATH/java/gdal.jar:/usr/share/java/gdal.jar:$CLASSPATH"
 
   export LD_LIBRARY_PATH="$NATIVE_PATH:$LD_LIBRARY_PATH"
@@ -323,7 +323,15 @@
 
 echo ---Detect maximum memory limit---
 # use previously set or detect RAM size in bytes
-RAM_SIZE=${RAM_SIZE-$(expr "$(awk '/MemTotal/{print $2}' /proc/meminfo)" \* 1024)}
+# Try Linux /proc/meminfo first, then FreeBSD sysctl
+if [ -z "$RAM_SIZE" ]; then
+  if [ -f /proc/meminfo ]; then
+    RAM_SIZE=$(expr "$(awk '/MemTotal/{print $2}' /proc/meminfo)" \* 1024)
+  elif command -v sysctl > /dev/null 2>&1; then
+    # FreeBSD: hw.physmem gives size in bytes
+    RAM_SIZE=$(sysctl -n hw.physmem 2>/dev/null)
+  fi
+fi
 if [ -n "$JAVA_MAXMEM" ]; then
   echo "max. memory limit defined via JAVA_MAXMEM=$JAVA_MAXMEM"
 elif ! is_number "$RAM_SIZE"; then
@@ -353,11 +361,22 @@
   echo set max. memory limit to $MEM_MAX_MB MiB
 fi
 
+
+# Check Java version and add necessary options for Java 9+
+java_version=$("$JAVA" -version 2>&1 | head -1)
+major_version=$(echo "$java_version" | sed -n 's/.*"\([0-9]*\).*/\1/p')
+if [ -z "$major_version" ]; then
+  major_version=$(echo "$java_version" | sed -n 's/.*version \([0-9]*\).*/\1/p')
+fi
+if [ "$major_version" -ge 9 ] 2>/dev/null; then
+  JAVA_OPTS="$JAVA_OPTS --add-opens java.base/java.lang=ALL-UNNAMED --add-opens java.base/jdk.internal.loader=ALL-UNNAMED --enable-native-access=ALL-UNNAMED"
+fi
+
 # eventually try to start if no errors so far
 if [ -z "$ERROR" ]; then
   echo ---Start OJ---
   # log.dir needs a trailing slash for path concatenation in log4j.xml
-"$JAVA" -Djava.system.class.loader=com.vividsolutions.jump.workbench.plugin.PlugInClassLoader -cp "$CLASSPATH" -Dlog.dir="$JUMP_SETTINGS/" $JAVA_OPTS $MAIN -state "$JUMP_SETTINGS/" $JUMP_OPTS "$@"
+"$JAVA" -Djava.library.path="$NATIVE_PATH" -Djava.system.class.loader=com.vividsolutions.jump.workbench.plugin.PlugInClassLoader -cp "$CLASSPATH" -Dlog.dir="$JUMP_SETTINGS/" $JAVA_OPTS $MAIN -state "$JUMP_SETTINGS/" $JUMP_OPTS "$@"
   # result of jre call
   ERROR=$?
 fi
