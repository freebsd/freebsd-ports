--- etc/profile.sh.orig	2009-12-23 15:53:06.000000000 +0100
+++ etc/profile.sh	2010-02-03 18:56:19.000000000 +0100
@@ -26,7 +26,7 @@
    export LD_LIBRARY_PATH=?HOME_PYTHON?/lib:$LD_LIBRARY_PATH
 fi
 
-if [ -z "$PATH" ]; then
+if [ -z "$PYTHONPATH" ]; then
    export PYTHONPATH=?ASRUN_SITE_PKG?
 else
    export PYTHONPATH=?ASRUN_SITE_PKG?:$PYTHONPATH
@@ -37,6 +37,13 @@
 # this should not be usefull...
 #export PYTHONHOME=?HOME_PYTHON?
 
+# Might be useful to fix errors on 64 bits platforms
+# See <http://www.code-aster.org/forum/read.php?f=11&i=1603&t=1574>
+HOME_MED=?HOME_MED?
+export HOME_MED
+HOME_HDF=?HOME_HDF?
+export HOME_HDF
+
 export WISHEXECUTABLE=?WISH_EXE?
 
 
