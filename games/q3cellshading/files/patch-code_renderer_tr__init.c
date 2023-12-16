--- code/renderer/tr_init.c.orig	2006-07-20 10:08:00 UTC
+++ code/renderer/tr_init.c
@@ -152,13 +152,6 @@ int		max_polys;
 cvar_t	*r_maxpolyverts;
 int		max_polyverts;
 
-void ( APIENTRY * qglMultiTexCoord2fARB )( GLenum texture, GLfloat s, GLfloat t );
-void ( APIENTRY * qglActiveTextureARB )( GLenum texture );
-void ( APIENTRY * qglClientActiveTextureARB )( GLenum texture );
-
-void ( APIENTRY * qglLockArraysEXT)( GLint, GLint);
-void ( APIENTRY * qglUnlockArraysEXT) ( void );
-
 static void AssertCvarRange( cvar_t *cv, float minVal, float maxVal, qboolean shouldBeIntegral )
 {
 	if ( shouldBeIntegral )
@@ -1040,7 +1033,7 @@ void R_Init( void ) {
 	Com_Memset( &backEnd, 0, sizeof( backEnd ) );
 	Com_Memset( &tess, 0, sizeof( tess ) );
 
-//	Swap_Init();
+	Swap_Init();
 
 	if ( (int)tess.xyz & 15 ) {
 		Com_Printf( "WARNING: tess.xyz not 16 byte aligned\n" );
