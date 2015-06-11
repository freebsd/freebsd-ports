--- docear.sh	2015-06-10 19:42:49.000000000 +0200
+++ /tmp/docear.sh.new	2015-06-10 19:41:56.000000000 +0200
@@ -190,6 +190,7 @@
 fi
 _debug "Calling: "\
 "${JAVACMD}" -Xmx512m\
+ "-Dawt.useSystemAAFontSettings=on"\
  "-Dorg.freeplane.param1=$1"\
  "-Dorg.freeplane.param2=$2"\
  "-Dorg.freeplane.param3=$3"\
@@ -204,6 +205,7 @@
  -xargs "${freedir}/init.xargs"
 ( echo "${DEBUG}" | grep -qe "exit" ) && exit 0 # do not start Freeplane
 "${JAVACMD}" -Xmx512m\
+ "-Dawt.useSystemAAFontSettings=on"\
  "-Dorg.freeplane.param1=$1"\
  "-Dorg.freeplane.param2=$2"\
  "-Dorg.freeplane.param3=$3"\
