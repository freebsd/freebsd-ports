--- clanbomber/ClanBomber.cpp.orig	Tue Aug 14 22:04:39 2001
+++ clanbomber/ClanBomber.cpp	Wed Nov 26 00:01:53 2003
@@ -593,6 +593,7 @@
 #ifdef MUSIC	
 	if (!wav && Config::get_music())
 	{
+		CL_SetupMikMod::init (0);
 		try
 		{
 			wav = CL_Streamed_MikModSample::create("music/bud.mod", NULL, true);
