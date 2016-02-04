--- bin/oj_linux.sh.orig	2016-01-08 09:30:28 UTC
+++ bin/oj_linux.sh
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
@@ -51,6 +53,7 @@ extract_libs(){
   # extract zipped files in native dir (our way to ship symlinks to desktops)
   for filepath in $(find "$1/" -name '*.tgz' -o -name '*.tar.gz')
   do
+    echo "#####  filepath = '$filepath'"
     file=$(basename "$filepath")
     folder=$(dirname "$filepath")
     done=".$file.unzipped"
@@ -74,6 +77,7 @@ postinstall(){
 
 macinstall(){
   # create app package
+  echo "#####  MACINSTALL"
   cp -R -a "$1"/bin/OpenJUMP.app/Contents "$1" &&\
   awk '{sub(/..\/oj_/,"bin/oj_",$0)}1' "$1"/bin/OpenJUMP.app/Contents/Resources/script > "$1"/Contents/Resources/script &&\
   echo patched oj.app
@@ -110,13 +114,19 @@ esac
 
 ## cd into jump home
 OLD_DIR=`pwd`
+echo "#####  pwd = '$OLD_DIR'"
 cd "$JUMP_HOME"
+PWD_DIR=`pwd`
+echo "##### cd '$JUMP_HOME', pwd = '$PWD_DIR'"
 
 ## determine where to place settings, if no path given
+echo "#####  ===== JUMP_SETTINGS = '$JUMP_SETTINGS'"
 [ -z "$JUMP_SETTINGS" ] && \
 JUMP_SETTINGS="$JUMP_HOME"; \
 if [ -d "$JUMP_SETTINGS" ]; then
+  echo "#####  within -d \$JUMP_SETTINGS"
   if [ ! -w "$JUMP_SETTINGS" ]; then
+    echo "#####  within ! -w \$JUMP_SETTINGS"
     # try users home dir
     JUMP_SETTINGS="$HOME/.openjump"
     # create if missing
@@ -134,14 +144,19 @@ fi
 # 1. first in oj_home/jre
 # 2. in configured java_home
 # 3. in path
+echo "#####  -----------------------------------------------------------"
+echo "#####  SEARCH JAVA:"
 if [ -f "$JUMP_HOME/jre/bin/java" ]; then
   JAVA="$JUMP_HOME/jre/bin/java"
+  echo "#####  JAVA = '$JAVA'"
 # is there a jre defined by env var?
 elif [ -n "$JAVA_HOME" ]; then
   JAVA=$JAVA_HOME/bin/java
+  echo "#####  JAVA = '$JAVA'"
 # well, let's look what we've got in the path
 else
   JAVA=`which java`
+  echo "#####  JAVA = '$JAVA'"
 fi
 
 # java available
@@ -150,24 +165,27 @@ fi
 add the location of java to your PATH environment variable." && ERROR=1 && end
 
 # resolve recursive links to java binary
+echo "#####  ===== Resolve recursive links to java binary: \$1 = '$1'"
 relPath "$JAVA" && JAVA="$(pwd)/$JAVA"
-while [ -L "${JAVA}" ]; do
-  JDIR=$(dirname "$JAVA")
-  JAVA_CANDIDATE=$(readlink -n "${JAVA}")
-  # protect against Gentoo's run-java-tool.bash wrapper
-  if [ $(basename "$JAVA") != $(basename "$JAVA_CANDIDATE") ]; then
-    break
-  fi
-  JAVA="$JAVA_CANDIDATE"
-  relPath "$JAVA" && JAVA="${JDIR}/${JAVA}"
-done
+echo "#####  awk script survived after \$1 test"
+#while [ -L "${JAVA}" ]; do
+#  JDIR=$(dirname "$JAVA")
+#  JAVA_CANDIDATE=$(readlink -n "${JAVA}")
+#  # protect against Gentoo's run-java-tool.bash wrapper
+#  if [ $(basename "$JAVA") != $(basename "$JAVA_CANDIDATE") ]; then
+#    break
+#  fi
+#  JAVA="$JAVA_CANDIDATE"
+#  relPath "$JAVA" && JAVA="${JDIR}/${JAVA}"
+#done
 # java executable file?
 [ ! -x "$JAVA" ] && \
  echo "The found java binary '$JAVA' is no executable file." && ERROR=1 && end
 
 # java version check
 JAVA_VERSIONSTRING="$("$JAVA" -version 2>&1)"
-JAVA_VERSION=$(echo $JAVA_VERSIONSTRING | awk -F'[ \056]' '{gsub(/["\047]+/,"")}/version [0-9]+\.[0-9]+/{print $3"."$4; exit}' )
+JAVA_VERSION=$(echo $JAVA_VERSIONSTRING | awk -F'"' '/^java version/ || /^openjdk version/{print $2}' | awk -F'.' '{print $1"."$2}')
+echo "#####  JAVA_VERSION = '$JAVA_VERSION'"
 JAVA_ARCH=$(echo $JAVA_VERSIONSTRING | grep -q -i 64-bit && echo x64 || echo x86)
 JAVA_NEEDED="1.6"
 if ! is_decimal "$JAVA_VERSION"; then
@@ -189,7 +207,7 @@ echo ---JAVA---
 echo "Using '$(basename "${JAVA}")' found in '$(dirname "${JAVA}")'"
 "$JAVA" -version 2>&1|awk 'BEGIN{ORS=""}{print $0"; "}END{print "\n"}'
 
-JUMP_PROFILE=~/.jump/openjump.profile
+JUMP_PROFILE="$HOME/.openjump/openjump.profile"
 if [ -f "$JUMP_PROFILE" ]; then
   source $JUMP_PROFILE
 fi
@@ -198,8 +216,13 @@ fi
 if [ -z "$JUMP_LIB" ]; then
   JUMP_LIB="./lib"
 fi
+echo "#####  JUMP_LIB = '$JUMP_LIB'"
+
 JUMP_NATIVE_DIR="$JUMP_LIB/native"
 JUMP_PLUGIN_DIR="${JUMP_PLUGIN_DIR:=$JUMP_LIB/ext}"
+echo "#####  -----------------------------------------------------------"
+echo "#####  JUMP_NATIVE_DIR = '$JUMP_NATIVE_DIR'"
+echo "#####  JUMP_PLUGIN_DIR = '$JUMP_PLUGIN_DIR'"
 
 JUMP_PLUGINS=./bin/default-plugins.xml
 if [ -z "$JUMP_PLUGINS" ] || [ ! -f "$JUMP_PLUGINS" ]; then
@@ -208,6 +231,7 @@ if [ -z "$JUMP_PLUGINS" ] || [ ! -f "$JU
     JUMP_PLUGINS="./scripts/default-plugins.xml"
   fi
 fi
+echo "#####  JUMP_PLUGINS = '$JUMP_PLUGINS'"
 
 # include every jar/zip in lib and native dir
 for libfile in "$JUMP_LIB/"*.zip "$JUMP_LIB/"*.jar "$JUMP_NATIVE_DIR/$JAVA_ARCH/"*.jar "$JUMP_NATIVE_DIR/"*.jar
@@ -216,29 +240,39 @@ do
 done
 CLASSPATH=.:./bin:./conf:$CLASSPATH
 export CLASSPATH;
+echo "#####  CLASSPATH = '$CLASSPATH'"
 
 ## compile jump opts
 #
 JUMP_OPTS="-plug-in-directory $JUMP_PLUGIN_DIR"
+echo "#####  JUMP_OPTS = '$JUMP_OPTS'"
 if [ -f "$JUMP_PLUGINS" ]; then
   JUMP_OPTS="$JUMP_OPTS -default-plugins $JUMP_PLUGINS"
+  echo "#####  JUMP_OPTS = '$JUMP_OPTS'"
 fi
+
 # workbench-properties.xml is used to manually load plugins (ISA uses this)
 JUMP_PROPERTIES=./bin/workbench-properties.xml
 if [ -n "$JUMP_PROPERTIES" ] && [ -f "$JUMP_PROPERTIES" ]; then
   JUMP_OPTS="$JUMP_OPTS -properties $JUMP_PROPERTIES"
+  echo "#####  JUMP_OPTS = '$JUMP_OPTS'"
 fi
 
 # compile jre opts, respect already set ones from e.g. mac
 JAVA_OPTS=""
+echo "#####  JAVA_OPTS = '$JAVA_OPTS'"
 JAVA_OPTS="$JAVA_OPTS $JAVA_MAXMEM $JAVA_LANG"
+echo "#####  JAVA_OPTS = '$JAVA_OPTS'"
 JAVA_OPTS="$JAVA_OPTS -Djump.home=."
+echo "#####  JAVA_OPTS = '$JAVA_OPTS'"
 [ -n "JAVA_SAXDRIVER"    ] && JAVA_OPTS="$JAVA_OPTS -Dorg.xml.sax.driver=$JAVA_SAXDRIVER"
 [ -n "$JAVA_LOOKANDFEEL" ] && JAVA_OPTS="$JAVA_OPTS -Dswing.defaultlaf=$JAVA_LOOKANDFEEL"
 JAVA_OPTS="$JAVA_OPTS $JAVA_OPTS_OVERRIDE"
+echo "#####  JAVA_OPTS = '$JAVA_OPTS'"
 
 # in case some additional archives were placed in native dir inbetween
-extract_libs "$JUMP_NATIVE_DIR"
+echo "#####  -----------------------------------------------------------"
+#extract_libs "$JUMP_NATIVE_DIR"
 
 # allow jre to find native libraries in native dir, lib/ext (backwards compatibility)
 NATIVE_PATH="$JUMP_NATIVE_DIR/$JAVA_ARCH:$JUMP_NATIVE_DIR:$JUMP_PLUGIN_DIR"
@@ -274,7 +308,11 @@ echo "$JUMP_SETTINGS/"
 
 echo ---Detect maximum memory limit---
 # use previously set or detect RAM size in bytes
-RAM_SIZE=${RAM_SIZE-$(expr "$(awk '/MemTotal/{print $2}' /proc/meminfo)" \* 1024)}
+#RAM_SIZE=${RAM_SIZE-$(expr "$(awk '/MemTotal/{print $2}' /proc/meminfo)" \* 1024)}
+RAM_SIZE=${RAM_SIZE-$(expr "$(sysctl hw.realmem | awk '/hw.realmem:/{print $2}')" / 1024)}
+echo "#####  -----------------------------------------------------------"
+echo "#####  RAM_SIZE = '$RAM_SIZE'"
+
 if [ -n "$JAVA_MAXMEM" ]; then
   echo "max. memory limit defined via JAVA_MAXMEM=$JAVA_MAXMEM"
 elif ! is_number "$RAM_SIZE"; then
@@ -292,14 +330,18 @@ else
   else
     MEM_MAX="$MEM_MINUS1GB"
   fi
+  echo "#####  MEM_MAX = '$MEM_MAX'"
 
   # limit 32bit jre to 2GiB = 2147483648 bytes
+  echo "#####  JAVA_ARCH = '$JAVA_ARCH'"
   if [ "$JAVA_ARCH" != "x64" ] && [ "$MEM_MAX" -gt "2147483648" ]; then
     MEM_MAX=2147483648
   fi
 
-  MEM_MAX_MB=`expr $MEM_MAX / 1024 / 1024`
+  MEM_MAX_MB=`expr $MEM_MAX / 1024`
   JAVA_MAXMEM="-Xmx${MEM_MAX_MB}M"
+  echo "#####  JAVA_MAXMEM = '$JAVA_MAXMEM'"
+
   # output info
   echo set max. memory limit to $MEM_MAX_MB MiB
 fi
@@ -318,3 +360,4 @@ cd "$OLD_DIR"
 
 ## run end function
 end
+
