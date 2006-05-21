--- ./game/q_shared.h.orig	Wed May 17 22:21:33 2006
+++ ./game/q_shared.h	Wed May 17 22:28:23 2006
@@ -315,7 +315,7 @@
 //float Q_fabs (float f);
 //#define	fabs(f) Q_fabs(f)
 //extern int sse2_enabled;
-#if !defined C_ONLY && !defined __linux__ && !defined __sgi && !defined SSE2 && !defined __FreeBSD__
+#if !defined C_ONLY && !defined __unix__ && !defined __sgi && !defined SSE2
 //extern void __cdecl Q_sseinit (void);
 void __cdecl Q_ftol2( float f, int *out );
 int __cdecl Q_ftol( float f );
