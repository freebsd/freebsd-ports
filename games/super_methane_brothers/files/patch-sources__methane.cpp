--- sources/methane.cpp.orig	2011-12-11 14:18:38.301132904 +0100
+++ sources/methane.cpp	2011-12-11 14:15:32.669126965 +0100
@@ -105,15 +105,15 @@
 				return 0;
 			}
 
-			CL_AutoPtr<CL_SetupSound> setup_sound;
-			CL_AutoPtr<CL_SoundOutput> sound_output;
-			CL_AutoPtr<CL_SetupMikMod> setup_mikmod;
+			CL_UniquePtr<CL_SetupSound> setup_sound;
+			CL_UniquePtr<CL_SoundOutput> sound_output;
+			CL_UniquePtr<CL_SetupMikMod> setup_mikmod;
 
 			if (GLOBAL_SoundEnable)
 			{
-				setup_sound = new CL_SetupSound;
-				sound_output = new CL_SoundOutput(44100);
-				setup_mikmod = new CL_SetupMikMod;
+				setup_sound = cl_move(CL_UniquePtr<CL_SetupSound>(new CL_SetupSound));
+				sound_output = cl_move(CL_UniquePtr<CL_SoundOutput>(new CL_SoundOutput(44100)));
+				setup_mikmod = cl_move(CL_UniquePtr<CL_SetupMikMod>(new CL_SetupMikMod));
 			}
 
 			// Set the video mode
