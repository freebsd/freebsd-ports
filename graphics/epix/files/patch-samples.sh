--- samples.sh.orig	Thu Sep  5 13:21:15 2002
+++ samples.sh	Thu Sep  5 13:21:26 2002
@@ -55,7 +55,7 @@
 	mv $TARBALL $EPIX_ROOTDIR/$SAMPLEDIR/$TARBALL
 
 	cd $EPIX_ROOTDIR/$SAMPLEDIR && tar -xf $TARBALL 
-	chown $USER.$USER * && chmod go+rX *
+	chown $USER:$GROUP * && chmod go+rX *
 	;;
 
     --uninstall)
