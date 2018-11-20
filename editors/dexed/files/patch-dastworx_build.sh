--- dastworx/build.sh	2018-10-22 01:38:52.000000000 -0500
+++ dastworx/build.sh	2018-11-06 01:09:50.779324000 -0500
@@ -1,35 +1,14 @@
-if [[ -z "$DC" ]]; then DC=dmd; fi
-if [[ "$DC" == "ldc" ]]; then DC=ldmd2; fi
-if [[ "$DC" == "gdc" ]]; then DC=gdmd; fi
-if [[ -z "$MFLAGS" ]]; then MFLAGS=-m64; fi
-
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
 cd ../
 
-echo building using $DC...
-
 #build
-$DC ${dast[@]} ${dparse[@]} ${iz[@]} ${stdxalloc[@]} \
--O -release -inline -boundscheck=off $MFLAGS \
--Isrc -I../etc/iz/import -I../etc/libdparse/src -I../etc/stdx-allocator/source \
--of../bin/dastworx
+
+%%LDMD2_CMD%% ${dast} \
+ -O -release -inline -boundscheck=off \
+-Isrc -I%%D_INCLUDE_DIR%% -L%%D_LIB_DIR%%/libiz.a -L%%D_LIB_DIR%%/libdparse.a \
+-L%%D_LIB_DIR%%/libstdx-allocator.a -of../bin/dastworx
 
 #cleanup
 rm ../bin/dastworx.o
