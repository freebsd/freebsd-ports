--- build/buildcheck.sh.orig	Fri Apr 26 17:39:27 2002
+++ build/buildcheck.sh	Fri Apr 26 17:39:47 2002
@@ -53,8 +53,8 @@
 #--------------------------------------------------------------------------
 # check for the correct version of Neon
 #
-NEON_WANTED_REGEX=0.19.[2-3]
-NEON_LATEST_WORKING_VER=0.19.3
+NEON_WANTED_REGEX=0.19.[2-4]
+NEON_LATEST_WORKING_VER=0.19.4
 NEON_URL="http://www.webdav.org/neon/neon-${NEON_LATEST_WORKING_VER}.tar.gz"
 if test -d ./neon; then
   NEON_VERSION="`./ac-helpers/get-neon-ver.sh neon`"
