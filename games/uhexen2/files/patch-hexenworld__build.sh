--- ./hexenworld/build.sh.orig	Sun Sep 24 14:24:48 2006
+++ ./hexenworld/build.sh	Tue Jan  9 17:01:16 2007
@@ -45,10 +45,13 @@
 echo "" && echo "Building hexenworld master server.."
 $MAKE_CMD -C Master || exit 1
 
+if [ "$USE_X86_ASM" = yes ]; then
 echo "" && echo "Building hexenworld client (software renderer)"
 $MAKE_CMD -C Client hw || exit 1
+$MAKE_CMD -s -C Client clean
+fi
 
 echo "" && echo "Building hexenworld client (opengl renderer)"
-$MAKE_CMD -s -C Client clean
 $MAKE_CMD -C Client glhw || exit 1
+$MAKE_CMD -s -C Client clean
 
