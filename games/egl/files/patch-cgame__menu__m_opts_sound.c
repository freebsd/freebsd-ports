--- ./cgame/menu/m_opts_sound.c.orig	Tue May 23 20:05:59 2006
+++ ./cgame/menu/m_opts_sound.c	Tue May 23 20:06:00 2006
@@ -60,7 +60,7 @@
 	uiList_t		cdtoggle_toggle;
 
 	// openal
-/*	uiAction_t		al_header;
+	uiAction_t		al_header;
 
 	uiSlider_t		dopplerfactor_slider;
 	uiAction_t		dopplerfactor_amount;
@@ -69,7 +69,7 @@
 
 	uiList_t		al_extensions_toggle;
 	uiList_t		al_ext_eax_toggle;
-*/
+
 	// software
 	uiAction_t		sw_header;
 	uiList_t		sw_quality_list;
@@ -94,14 +94,14 @@
 
 static void ALDopFactorFunc (void *unused)
 {
-//	cgi.Cvar_SetValue ("al_dopplerfactor", m_soundMenu.dopplerfactor_slider.curValue * 0.1, qFalse);
-//	m_soundMenu.dopplerfactor_amount.generic.name = cgi.Cvar_GetStringValue ("al_dopplerfactor");
+	cgi.Cvar_SetValue ("al_dopplerfactor", m_soundMenu.dopplerfactor_slider.curValue * 0.1, qFalse);
+	m_soundMenu.dopplerfactor_amount.generic.name = cgi.Cvar_GetStringValue ("al_dopplerfactor");
 }
 
 static void ALDopVelocityFunc (void *unused)
 {
-//	cgi.Cvar_SetValue ("al_dopplervelocity", m_soundMenu.dopplervelocity_slider.curValue * 100, qFalse);
-//	m_soundMenu.dopplervelocity_amount.generic.name = cgi.Cvar_GetStringValue ("al_dopplervelocity");
+	cgi.Cvar_SetValue ("al_dopplervelocity", m_soundMenu.dopplervelocity_slider.curValue * 100, qFalse);
+	m_soundMenu.dopplervelocity_amount.generic.name = cgi.Cvar_GetStringValue ("al_dopplervelocity");
 }
 
 static void ALExtensionsFunc (void *unused)
@@ -152,8 +152,7 @@
 */
 static void SoundMenu_SetValues (void)
 {
-//	cgi.Cvar_SetValue ("s_initSound",	clamp (cgi.Cvar_GetIntegerValue ("s_initSound"), 0, 2), qTrue);
-	cgi.Cvar_SetValue ("s_initSound",	clamp (cgi.Cvar_GetIntegerValue ("s_initSound"), 0, 1), qTrue);
+	cgi.Cvar_SetValue ("s_initSound",	clamp (cgi.Cvar_GetIntegerValue ("s_initSound"), 0, 2), qTrue);
 	m_soundMenu.sound_toggle.curValue		= cgi.Cvar_GetIntegerValue ("s_initSound");
 
 	m_soundMenu.sfxvolume_slider.curValue		= cgi.Cvar_GetFloatValue ("s_volume") * 20;
@@ -207,8 +206,8 @@
 
 	static char *soundinit_items[] = {
 		"off",
-		"on",
-//		"OpenAL [ EXPERIMENTAL ]",
+		"OSS",
+		"OpenAL [UNSTABLE]",
 		0
 	};
 
@@ -256,7 +255,7 @@
 	m_soundMenu.cdtoggle_toggle.generic.statusBar	= "Toggle CD Play";
 
 	// openal
-/*	m_soundMenu.al_header.generic.type		= UITYPE_ACTION;
+	m_soundMenu.al_header.generic.type		= UITYPE_ACTION;
 	m_soundMenu.al_header.generic.flags		= UIF_NOSELECT|UIF_CENTERED|UIF_MEDIUM|UIF_SHADOW;
 	m_soundMenu.al_header.generic.name		= "OpenAL Sound Settings";
 
@@ -289,7 +288,7 @@
 	m_soundMenu.al_ext_eax_toggle.generic.callBack		= ALExtEAXFunc;
 	m_soundMenu.al_ext_eax_toggle.itemNames				= soundinit_items;
 	m_soundMenu.al_ext_eax_toggle.generic.statusBar		= "Toggle the OpenAL extension EAX 2.0";		
-*/
+
 	// software
 	m_soundMenu.sw_header.generic.type		= UITYPE_ACTION;
 	m_soundMenu.sw_header.generic.flags		= UIF_NOSELECT|UIF_CENTERED|UIF_MEDIUM|UIF_SHADOW;
