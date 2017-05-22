--- code/client/snd_openal.c.orig	2011-12-24 12:29:31 UTC
+++ code/client/snd_openal.c
@@ -2072,7 +2072,7 @@ static cvar_t *s_alCapture;
 #elif defined(MACOS_X)
 #define ALDRIVER_DEFAULT "/System/Library/Frameworks/OpenAL.framework/OpenAL"
 #else
-#define ALDRIVER_DEFAULT "libopenal.so.1"
+#define ALDRIVER_DEFAULT "libopenal.so"
 #endif
 
 /*
@@ -2358,6 +2358,12 @@ qboolean S_AL_Init( soundInterface_t *si
 
 	s_alDevice = Cvar_Get("s_alDevice", "", CVAR_ARCHIVE | CVAR_LATCH);
 
+	if ( COM_CompareExtension( s_alDriver->string, ".pk3" ) )
+	{
+		Com_Printf( S_COLOR_RED "Rejecting s_alDriver named \"%s\"\n", s_alDriver->string );
+		return qfalse;
+	}
+
 	// Load QAL
 	if( !QAL_Init( s_alDriver->string ) )
 	{
