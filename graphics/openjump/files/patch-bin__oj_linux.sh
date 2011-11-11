--- bin/oj_linux.sh.orig	2011-09-11 12:55:32.000000000 +0200
+++ bin/oj_linux.sh	2011-10-23 09:46:55.000000000 +0200
@@ -1,7 +1,7 @@
 #!/bin/sh
 
 ## uncomment and put the path to your jre here
-#JAVA_HOME="/home/ed/jre1.6.0_21"
+JAVA_HOME="/usr/local/"
 
 ## uncomment and change your memory configuration here 
 ## Xms is initial size, Xmx is maximum size
@@ -75,13 +75,13 @@
  echo "The found java binary '$JAVA' is no executable file." && ERROR=1 && end
 
 # java version check
-JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/{print $2}' | awk -F'.' '{print $1"."$2}')
-JAVA_NEEDED="1.5"
-if ! awk "BEGIN{if($JAVA_VERSION < $JAVA_NEEDED)exit 1}"; then
-  echo "Your java version '$JAVA_VERSION' is insufficient to run openjump.
-Please provide an at least version '$JAVA_NEEDED' java runtime."
-  ERROR=1
-fi
+#JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/{print $2}' | awk -F'.' '{print $1"."$2}')
+#JAVA_NEEDED="1.5"
+#if ! awk "BEGIN{if($JAVA_VERSION < $JAVA_NEEDED)exit 1}"; then
+#  echo "Your java version '$JAVA_VERSION' is insufficient to run openjump.
+#Please provide an at least version '$JAVA_NEEDED' java runtime."
+#  ERROR=1
+#fi
 
 # always print java infos
 echo "Running -> '${JAVA}'; " $("$JAVA" -version 2>&1|awk 'BEGIN{ORS=""}{print $0"; "}')
