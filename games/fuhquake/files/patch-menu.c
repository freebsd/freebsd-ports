--- menu.c.orig	Wed Jan  7 01:02:12 2004
+++ menu.c	Tue Jan 31 13:49:29 2006
@@ -411,9 +411,11 @@
 		Cvar_SetValue (&cl_hudswap, !cl_hudswap.value);
 		break;
 
+#ifndef NO_WINDOWED_MOUSE
 	case 17:	// _windowed_mouse
 		Cvar_SetValue (&_windowed_mouse, !_windowed_mouse.value);
 		break;
+#endif
 	}
 }
 
@@ -873,24 +875,24 @@
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
@@ -1225,8 +1227,6 @@
 
 	
 	progs = (dprograms_t *) FS_LoadHunkFile ("spprogs.dat");
-	if (progs && !file_from_gamedir)	
-		Cbuf_AddText ("gamedir qw\n");
 	Cbuf_AddText ("map start\n");
 }
 
@@ -1385,7 +1385,7 @@
 		return;
 
 	M_EnterMenu (m_load);
-	M_ScanSaves (!file_from_gamedir ? "qw" : com_gamedir);
+	M_ScanSaves (com_gamedir);
 }
 
 void M_Menu_Save_f (void) {
@@ -1443,7 +1443,7 @@
 
 		// issue the load command
 		if (FS_LoadHunkFile ("spprogs.dat") && !file_from_gamedir)
-			Cbuf_AddText("disconnect; gamedir qw\n");
+			Cbuf_AddText("disconnect\n");
 		Cbuf_AddText (va ("load s%i\n", load_cursor) );
 		return;
 
@@ -2209,7 +2209,7 @@
 		return;
 	}
 #else
-	if (!(d = opendir(va("%s%s", com_basedir, demo_currentdir)))) {
+	if (!(d = opendir(va("%s/%s", com_gamedir, demo_currentdir)))) {
 		demolist_data[demolist_count].name = strdup ("Error reading directory");
 		demolist_data[demolist_count].type = dt_msg;
 		demolist_count++;
@@ -2315,7 +2315,7 @@
 					*s = 0;
 			}
 		} else {
-			strcpy(demo_currentdir, "/qw");	
+			strcpy(demo_currentdir, com_gamedir);
 		}
 	}
 	
