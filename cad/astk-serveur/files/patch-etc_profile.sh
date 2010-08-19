--- etc/profile.sh.orig	2010-07-07 18:18:08.000000000 +0200
+++ etc/profile.sh	2010-08-11 19:07:22.000000000 +0200
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
 
 
