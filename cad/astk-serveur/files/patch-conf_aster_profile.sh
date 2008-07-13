--- conf/aster_profile.sh.orig	2008-04-10 19:13:17.000000000 +0200
+++ conf/aster_profile.sh	2008-07-06 19:18:01.000000000 +0200
@@ -18,4 +18,10 @@
 #PYTHONHOME=?HOME_PYTHON?
 #export PYTHONHOME
 
+# Might be useful to fix errors on 64 bits platforms
+# See <http://www.code-aster.org/forum/read.php?f=11&i=1603&t=1574>
+HOME_MED=?HOME_MED?
+export HOME_MED
+HOME_HDF=?HOME_HDF?
+export HOME_HDF
 
