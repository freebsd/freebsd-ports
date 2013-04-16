--- bin/oj_linux.sh.orig	2012-12-31 17:00:38.000000000 +0100
+++ bin/oj_linux.sh	2013-04-13 22:28:29.000000000 +0200
@@ -3,7 +3,7 @@
 ## uncomment and put in the path where oj log, settings should end up
 ## if unset defaults to
 ##   JUMP_HOME (oj app folder) if writable or $HOME/.openjump (user home)
-#JUMP_SETTINGS="/tmp/foobar"
+JAVA_HOME="/usr/local"
 
 ## uncomment and put the path to your jre here
 #JAVA_HOME="/home/ed/jre1.6.0_21"
@@ -126,7 +126,7 @@
  echo "The found java binary '$JAVA' is no executable file." && ERROR=1 && end
 
 # java version check
-JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/{print $2}' | awk -F'.' '{print $1"."$2}')
+JAVA_VERSION=$("$JAVA" -version 2>&1 | awk -F'"' '/^java version/ || /^openjdk version/{print $2}' | awk -F'.' '{print $1"."$2}')
 JAVA_NEEDED="1.5"
 if ! awk "BEGIN{if($JAVA_VERSION < $JAVA_NEEDED)exit 1}"; then
   echo "Your java version '$JAVA_VERSION' is insufficient to run openjump.
