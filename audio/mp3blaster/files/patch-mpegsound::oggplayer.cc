
$FreeBSD$

--- mpegsound/oggplayer.cc.orig	Mon Dec  1 21:30:07 2003
+++ mpegsound/oggplayer.cc	Mon Dec  1 21:30:17 2003
@@ -23,7 +23,7 @@
 /* Martijn suggests that big endiannes is already taken care of in the rawplayer
  * class.
  */
-#if 0 && defined(WORDS_BIGENDIAN)
+#if defined(WORDS_BIGENDIAN)
 	bigendian = 1;
 #endif
 	//TODO: On what hardware is data unsigned, and how do I know?
