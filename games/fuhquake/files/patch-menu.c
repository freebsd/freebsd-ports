--- menu.c.orig	Thu Feb  5 00:33:07 2004
+++ menu.c	Thu Feb  5 00:34:32 2004
@@ -411,9 +436,11 @@
 		Cvar_SetValue (&cl_hudswap, !cl_hudswap.value);
 		break;
 
+#ifndef NO_WINDOWED_MOUSE
 	case 17:	// _windowed_mouse
 		Cvar_SetValue (&_windowed_mouse, !_windowed_mouse.value);
 		break;
+#endif
 	}
 }
 
@@ -873,24 +900,24 @@
 	M_Print (16, 96, "        Pickup flashes");
 	M_DrawCheckbox (ALIGN_FPS_OPTIONS, 96, v_bonusflash.value);
 
-	M_Print (16, 104, "         Powerup glow");
+	M_Print (16, 104, "          Powerup glow");
 	M_Print (ALIGN_FPS_OPTIONS, 104, r_powerupglow.value==2 ? "own off" :
 		r_powerupglow.value ? "on" : "off");
 
-	M_Print (16, 112, "         Draw torches");
+	M_Print (16, 112, "          Draw torches");
 	M_DrawCheckbox (ALIGN_FPS_OPTIONS, 112, r_drawflame.value);
 
-	M_Print (16, 120, "             Fast sky");
+	M_Print (16, 120, "              Fast sky");
 	M_DrawCheckbox (ALIGN_FPS_OPTIONS, 120, r_fastsky.value);
 
 #ifdef GLQUAKE
-	M_Print (16, 128, "          Fast lights");
+	M_Print (16, 128, "           Fast lights");
 	M_DrawCheckbox (ALIGN_FPS_OPTIONS, 128, gl_flashblend.value);
 #endif
 
-	M_PrintWhite (16, 136, "            Fast mode");
+	M_PrintWhite (16, 136, "             Fast mode");
 
-	M_PrintWhite (16, 144, "         High quality");
+	M_PrintWhite (16, 144, "          High quality");
 
 // cursor
 	M_DrawCharacter (196, 32 + fps_cursor * 8, 12 + ((int) (curtime * 4) & 1));
