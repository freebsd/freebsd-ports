--- hexenworld/build.sh.orig	2007-10-18 13:55:49.000000000 -0300
+++ hexenworld/build.sh	2008-04-22 22:52:13.000000000 -0300
@@ -41,8 +41,9 @@
 
 echo "" && echo "Building hexenworld client (software renderer)"
 $MAKE_CMD -C Client hw || exit 1
+$MAKE_CMD -s -C Client clean
 
 echo "" && echo "Building hexenworld client (opengl renderer)"
-$MAKE_CMD -s -C Client clean
 $MAKE_CMD -C Client glhw || exit 1
+$MAKE_CMD -s -C Client clean
 
