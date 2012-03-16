--- ./src/Config.pri.orig	2012-03-05 23:22:23.000000000 +0100
+++ ./src/Config.pri	2012-03-05 23:22:47.000000000 +0100
@@ -13,6 +13,7 @@
         REVISION="-git"
     }
 }
+REVISION="-dev"
 
 win32|macx {
     system(echo $${LITERAL_HASH}define SVNREV $${SVNREV} > revision.h )
