--- bin/oj_linux.sh.orig	2012-01-25 20:15:16.000000000 +0100
+++ bin/oj_linux.sh	2012-03-10 18:01:15.000000000 +0100
@@ -6,7 +6,7 @@
 #JUMP_SETTINGS="/tmp/foobar"
 
 ## uncomment and put the path to your jre here
-#JAVA_HOME="/home/ed/jre1.6.0_21"
+JAVA_HOME="/usr/local"
 
 ## uncomment and change your memory configuration here 
 ## Xms is initial size, Xmx is maximum size
@@ -121,7 +121,7 @@
  echo "The found java binary '$JAVA' is no executable file." && ERROR=1 && end
 
 # java version check
-JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/{print $2}' | awk -F'.' '{print $1"."$2}')
+JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/ || /^openjdk version/{print $2}' | awk -F'.' '{print $1"."$2}')
 JAVA_NEEDED="1.5"
 if ! awk "BEGIN{if($JAVA_VERSION < $JAVA_NEEDED)exit 1}"; then
   echo "Your java version '$JAVA_VERSION' is insufficient to run openjump.
