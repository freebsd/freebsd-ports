--- src/alc/alc_context.c~	Tue Aug  1 02:10:18 2000
+++ src/alc/alc_context.c	Mon Sep 25 19:20:23 2000
@@ -65,7 +65,7 @@
 static ALCenum _alcDestroyContext(AL_context *cc);
 static void    _alcReallocContexts(ALuint newsize);
 static int     _alcCidToIndex(ALuint cid);
-static ALuint  _alcIndexToCid(int index);
+static ALuint  _alcIndexToCid(int idx);
 
 #ifdef JLIB
 unsigned int jlib_debug = 0;
@@ -777,8 +777,8 @@
 	return cid - CONTEXT_BASE;
 }
 
-static ALuint _alcIndexToCid(int index) {
-	return index + CONTEXT_BASE;
+static ALuint _alcIndexToCid(int idx) {
+	return idx + CONTEXT_BASE;
 }
 
 /*
