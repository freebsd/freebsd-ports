--- dastworx/build.sh	2017-07-21 05:32:58 UTC
+++ dastworx/build.sh
@@ -1,13 +1,3 @@
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
 #dast sources
 cd src/
 dast=$(find `pwd` -type f -name \*.d)
@@ -16,12 +6,12 @@ cd ../
 echo building...
 
 #build
-dmd ${dast[@]} ${dparse[@]} ${iz[@]} \
+%%LDMD2_CMD%% ${dast} \
 -O -release -inline -boundscheck=off \
--Isrc -I../etc/iz/import -I../etc/libdparse/src \
+-Isrc -I%%D_INCLUDE_DIR%% -L%%D_LIB_DIR%%/libiz.a -L%%D_LIB_DIR%%/libdparse.a \
 -of../bin/dastworx
 
 #cleanup
 rm ../bin/dastworx.o
 
-echo ...done
\ No newline at end of file
+echo ...done
