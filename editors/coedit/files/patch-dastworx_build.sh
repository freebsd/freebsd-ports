--- dastworx/build.sh	2018-02-11 21:48:35.000000000 -0500
+++ dastworx/build.sh	2018-02-12 12:01:10.311013000 -0500
@@ -1,18 +1,3 @@
-#iz sources
-cd ../etc/iz/import/
-iz=$(find `pwd` -type f -name \*.d)
-cd ../../../dastworx
-
-#dparse sources
-cd ../etc/libdparse/src/
-dparse=$(find `pwd` -type f -name \*.d)
-cd ../../../dastworx
-
-#stdx-alloc sources
-cd ../etc/stdx-allocator/source/
-stdxalloc=$(find `pwd` -type f -name \*.d)
-cd ../../../dastworx
-
 #dast sources
 cd src/
 dast=$(find `pwd` -type f -name \*.d)
@@ -21,9 +6,9 @@
 echo building...
 
 #build
-dmd ${dast[@]} ${dparse[@]} ${iz[@]} ${stdxalloc[@]} \
+%%LDMD2_CMD%% ${dast}  \
 -O -release -inline -boundscheck=off \
--Isrc -I../etc/iz/import -I../etc/libdparse/src -I../etc/stdx-allocator/source \
+-Isrc -I%%D_INCLUDE_DIR%% -L%%D_LIB_DIR%%/libiz.a -L%%D_LIB_DIR%%/libdparse.a \
 -of../bin/dastworx
 
 #cleanup
