--- conf/aster_profile.sh.orig	Thu Oct 27 18:32:14 2005
+++ conf/aster_profile.sh	Wed Jan 11 22:08:53 2006
@@ -15,6 +15,13 @@
 # unlimit corefile size
 ulimit -c unlimited
 
+# Might be useful to fix errors on 64 bits platforms
+# See <http://www.code-aster.org/forum/read.php?f=11&i=1603&t=1574>
+HOME_MED=?HOME_MED?
+export HOME_MED
+HOME_HDF=?HOME_HDF?
+export HOME_HDF
+
 # optional settings
 # DO NOT EDIT FOLLOWING LINE !
 #?OPT_ENV?
