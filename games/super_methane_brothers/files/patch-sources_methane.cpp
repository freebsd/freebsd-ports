--- sources/methane.cpp.orig	2011-04-05 07:08:02 UTC
+++ sources/methane.cpp
@@ -12,10 +12,17 @@
 //------------------------------------------------------------------------------
 // Methane brothers main source file
 //------------------------------------------------------------------------------
+
+#if !defined(__i386__) && !defined(__x86_64__)
+#define CL_DISABLE_SSE2
+#endif
+
 #include <ClanLib/core.h>
 #include <ClanLib/application.h>
 #include <ClanLib/display.h>
+#ifndef CL_DISABLE_SSE2
 #include <ClanLib/swrender.h>
+#endif
 #include <ClanLib/gl.h>
 #include <ClanLib/gl1.h>
 #include <ClanLib/sound.h>
@@ -54,10 +61,14 @@ class SuperMethaneBrothers (public)
 		{
 			CL_SetupGL target_opengl2;
 			CL_SetupGL1 target_opengl1;
+#ifndef CL_DISABLE_SSE2
 			CL_SetupSWRender target_swrender;
 
 			// Since SWRender is compatible and fast - Use that as the default setting options
 			target_swrender.set_current();
+#else
+			target_opengl2.set_current();
+#endif
 
 			if (get_options())
 			{
@@ -69,9 +80,11 @@ class SuperMethaneBrothers (public)
 					case (opengl1):
 						target_opengl1.set_current();
 						break;
+#ifndef CL_DISABLE_SSE2
 					case (swrender):
 						target_swrender.set_current();
 						break;
+#endif
 				}
 			}
 			else
@@ -80,15 +93,15 @@ class SuperMethaneBrothers (public)
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
@@ -302,11 +315,13 @@ class SuperMethaneBrothers (public)
 				LastKey = 0;
 				GLOBAL_RenderTarget = opengl1;
 			}
+#ifndef CL_DISABLE_SSE2
 			if ( (LastKey == 'r') || (LastKey == 'R') )
 			{
 				LastKey = 0;
 				GLOBAL_RenderTarget = swrender;
 			}
+#endif
 
 			gc.clear(CL_Colorf(0.0f,0.0f,0.2f));
 
@@ -330,6 +345,7 @@ class SuperMethaneBrothers (public)
 			{
 				options_font.draw_text(gc, 10, ypos, "OpenGL V1 - Disabled. Press 'E' to select");
 			}
+#ifndef CL_DISABLE_SSE2
 			ypos += 50;
 			if (GLOBAL_RenderTarget == swrender)
 			{
@@ -339,6 +355,7 @@ class SuperMethaneBrothers (public)
 			{
 				options_font.draw_text(gc, 10, ypos, "Software Renderer - Disabled. Press 'R' to select");
 			}
+#endif
 			ypos += 100;
 			if (GLOBAL_SoundEnable)
 			{
