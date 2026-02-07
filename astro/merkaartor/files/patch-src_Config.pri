--- src/Config.pri.orig	2022-06-11 16:26:36 UTC
+++ src/Config.pri
@@ -1,11 +1,7 @@
 # see http://merkaartor.be/wiki/merkaartor/Compiling
 
-REVISION = $$system( git describe --tags )
-VERSION = $$system( git describe --tags HEAD | sed "'s/-g.*//;s/-/./g'" )
-isEmpty( REVISION ) {
-	REVISION = $$system(head -n 3 ../CHANGELOG | tail -n 1 | sed "'s/^v//'")
-	VERSION = $$REVISION
-}
+REVISION = $$system(head -n 3 ../CHANGELOG | tail -n 1 | sed "'s/^v//'")
+VERSION = $$REVISION
 
 ARCH=""
 BITS=""
