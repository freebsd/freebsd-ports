--- dastworx/build.sh	2018-06-03 02:41:09.063965000 -0500
+++ dastworx/build.sh	2018-06-03 02:42:21.888100000 -0500
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
@@ -21,10 +6,10 @@
 echo building...
 
 #build
-dmd ${dast[@]} ${dparse[@]} ${iz[@]} ${stdxalloc[@]} \
+%%LDMD2_CMD%% ${dast} \
 -O -release -inline -boundscheck=off \
--Isrc -I../etc/iz/import -I../etc/libdparse/src -I../etc/stdx-allocator/source \
--of../bin/dastworx
+-Isrc -I%%D_INCLUDE_DIR%% -L%%D_LIB_DIR%%/libiz.a -L%%D_LIB_DIR%%/libdparse.a \
+-L%%D_LIB_DIR%%/libstdx-allocator.a -of../bin/dastworx
 
 #cleanup
 rm ../bin/dastworx.o
