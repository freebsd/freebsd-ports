--- menu.c.orig	Wed May 21 17:18:36 2003
+++ menu.c	Tue May 27 23:06:19 2003
@@ -62,6 +62,7 @@
 		void M_Menu_Fps_f (void);
 		void M_Menu_Video_f (void);
 	void M_Menu_MP3_Control_f (void);
+	void M_Menu_Help_f (void);
 	void M_Menu_Quit_f (void);
 
 void M_Main_Draw (void);
@@ -78,6 +79,7 @@
 		void M_Keys_Draw (void);
 		void M_Fps_Draw (void);
 		void M_Video_Draw (void);
+	void M_MP3_Control_Draw (void);
 	void M_Help_Draw (void);
 	void M_Quit_Draw (void);
 
@@ -95,6 +97,7 @@
 		void M_Keys_Key (int key);
 		void M_Fps_Key (int key);
 		void M_Video_Key (int key);
+	void M_MP3_Control_Key (int key);
 	void M_Help_Key (int key);
 	void M_Quit_Key (int key);
 
@@ -251,7 +254,11 @@
 /* MAIN MENU */
 
 int	m_main_cursor;
+#if defined(_WIN32) || defined(__XMMS__)
+#define	MAIN_ITEMS	6
+#else
 #define	MAIN_ITEMS	5
+#endif
 
 
 void M_Menu_Main_f (void) {
@@ -269,7 +276,13 @@
 	M_DrawTransPic (16, 4, Draw_CachePic ("gfx/qplaque.lmp") );
 	p = Draw_CachePic ("gfx/ttl_main.lmp");
 	M_DrawPic ( (320-p->width)/2, 4, p);
-	M_DrawTransPic (72, 32, Draw_CachePic ("gfx/mainmenu.lmp") );
+	M_DrawTransPic (72, 32, Draw_CachePic
+#if defined(_WIN32) || defined(__XMMS__)
+	("gfx/mainmenu_mp3.lmp")
+#else
+	("gfx/mainmenu.lmp")
+#endif
+	);
 
 	f = (int)(curtime * 10)%6;
 	
@@ -332,7 +345,19 @@
 			break;
 	#endif
 
+	#if defined(_WIN32) || defined(__XMMS__)
 		case 4:
+	#else
+		case 3:
+	#endif
+			M_Menu_Help_f ();
+			break;
+
+	#if defined(_WIN32) || defined(__XMMS__)
+		case 5:
+	#else
+		case 4:
+	#endif
 			M_Menu_Quit_f ();
 			break;
 		}
@@ -442,9 +467,11 @@
 		Cvar_SetValue (&cl_hudswap, !cl_hudswap.value);
 		break;
 
+#ifndef NO_WINDOWED_MOUSE
 	case 17:	// _windowed_mouse
 		Cvar_SetValue (&_windowed_mouse, !_windowed_mouse.value);
 		break;
+#endif
 	}
 }
 
@@ -491,25 +518,25 @@
 	r = v_contrast.value - 1.0;
 	M_DrawSlider (220, 72, r);
 
-	M_Print (16, 80, "           Mouse Speed");
+	M_Print (16, 80, "           Mouse speed");
 	r = (sensitivity.value - 1)/10;
 	M_DrawSlider (220, 80, r);
 
-	M_Print (16, 88, "       CD Music Volume");
+	M_Print (16, 88, "       CD music volume");
 	r = bgmvolume.value;
 	M_DrawSlider (220, 88, r);
 
-	M_Print (16, 96, "          Sound Volume");
+	M_Print (16, 96, "          Sound volume");
 	r = s_volume.value;
 	M_DrawSlider (220, 96, r);
 
-	M_Print (16, 104,  "            Always Run");
+	M_Print (16, 104,  "            Always run");
 	M_DrawCheckbox (220, 104, cl_forwardspeed.value > 200);
 
 	M_Print (16, 112, "            Mouse look");
 	M_DrawCheckbox (220, 112, freelook.value);
 
-	M_Print (16, 120, "          Invert Mouse");
+	M_Print (16, 120, "          Invert mouse");
 	M_DrawCheckbox (220, 120, m_pitch.value < 0);
 
 	M_Print (16, 128, "            Lookstrafe");
@@ -524,17 +551,19 @@
 	M_Print (16, 152, "          FPS settings");
 
 	if (vid_menudrawfn)
-		M_Print (16, 160, "           Video Modes");
+		M_Print (16, 160, "           Video modes");
 
+#ifndef NO_WINDOWED_MOUSE
 #ifdef _WIN32
 	if (modestate == MS_WINDOWED)
 	{
 #endif
-		M_Print (16, 168, "             Use Mouse");
+		M_Print (16, 168, "             Use mouse");
 		M_DrawCheckbox (220, 168, _windowed_mouse.value);
 #ifdef _WIN32
 	}
 #endif
+#endif /* NO_WINDOWED_MOUSE */
 
 // cursor
 	M_DrawCharacter (200, 32 + options_cursor*8, 12+((int)(curtime*4)&1));
@@ -611,22 +640,34 @@
 		break;
 	}
 
-	if (options_cursor == 16 && vid_menudrawfn == NULL) {
-		if (k == K_UPARROW || k == K_END || k == K_PGDN)
+	if (k == K_UPARROW || k == K_END || k == K_PGDN)
+	{
+#ifdef NO_WINDOWED_MOUSE
+		if ((options_cursor == 17)
+#ifdef _WIN32
+		&& (modestate != MS_WINDOWED)
+#endif
+		)
+			options_cursor = 16;
+#endif /* NO_WINDOWED_MOUSE */
+
+		if (options_cursor == 16 && vid_menudrawfn == NULL)
 			options_cursor = 15;
-		else
-			options_cursor = 0;
 	}
+	else
+	{
+		if (options_cursor == 16 && vid_menudrawfn == NULL)
+			options_cursor = 17;
 
-	if ((options_cursor == 17)
+#ifdef NO_WINDOWED_MOUSE
+		if ((options_cursor == 17)
 #ifdef _WIN32
-	&& (modestate != MS_WINDOWED)
+		&& (modestate != MS_WINDOWED)
 #endif
-	)
-	if (k == K_UPARROW || k == K_END || k == K_PGDN)
-		options_cursor = 16;
-	else
-		options_cursor = 0;
+		)
+			options_cursor = 0;
+#endif /* NO_WINDOWED_MOUSE */
+	}
 }
 
 
@@ -894,24 +935,24 @@
 	M_Print (16, 96, "        Pickup flashes");
 	M_DrawCheckbox (220, 96, v_bonusflash.value);
 
-	M_Print (16, 104, "         Powerup glow");
+	M_Print (16, 104, "          Powerup glow");
 	M_Print (220, 104, r_powerupglow.value==2 ? "own off" :
 		r_powerupglow.value ? "on" : "off");
 
-	M_Print (16, 112, "         Draw torches");
+	M_Print (16, 112, "          Draw torches");
 	M_DrawCheckbox (220, 112, r_drawflame.value);
 
-	M_Print (16, 120, "             Fast sky");
+	M_Print (16, 120, "              Fast sky");
 	M_DrawCheckbox (220, 120, r_fastsky.value);
 
 #ifdef GLQUAKE
-	M_Print (16, 128, "          Fast lights");
+	M_Print (16, 128, "           Fast lights");
 	M_DrawCheckbox (220, 128, gl_flashblend.value);
 #endif
 
-	M_PrintWhite (16, 136, "            Fast mode");
+	M_PrintWhite (16, 136, "             Fast mode");
 
-	M_PrintWhite (16, 144, "         High quality");
+	M_PrintWhite (16, 144, "          High quality");
 
 // cursor
 	M_DrawCharacter (200, 32 + fps_cursor*8, 12+((int)(curtime*4)&1));
