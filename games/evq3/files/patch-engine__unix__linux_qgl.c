--- engine/unix/linux_qgl.c.orig	Fri Apr 20 15:49:55 2007
+++ engine/unix/linux_qgl.c	Fri Apr 20 15:52:28 2007
@@ -2672,8 +2672,10 @@
 		// placing a short delay before libGL is unloaded works around the problem.
 		// This delay is changable via the r_GLlibCoolDownMsec cvar (nice name
 		// huh?), and it defaults to 0. For me, 500 seems to work.
+#if 0
 		if( r_GLlibCoolDownMsec->integer )
 			usleep( r_GLlibCoolDownMsec->integer * 1000 );
+#endif
 
 		#if USE_SDL_VIDEO
 		SDL_QuitSubSystem(SDL_INIT_VIDEO);
