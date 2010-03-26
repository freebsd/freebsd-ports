--- ./etc/profile.csh.orig	2009-12-23 15:53:06.000000000 +0100
+++ ./etc/profile.csh	2010-01-10 21:45:50.000000000 +0100
@@ -38,6 +38,11 @@
 # this should not be usefull...
 #setenv PYTHONHOME ?HOME_PYTHON?
 
+# Might be useful to fix errors on 64 bits platforms
+# See <http://www.code-aster.org/forum/read.php?f=11&i=1603&t=1574>
+setenv HOME_MED ?HOME_MED?
+setenv HOME_HDF ?HOME_HDF?
+
 setenv WISHEXECUTABLE ?WISH_EXE?
 
 
