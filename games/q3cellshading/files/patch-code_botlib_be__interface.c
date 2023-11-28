--- code/botlib/be_interface.c.orig	2006-07-18 09:53:28 UTC
+++ code/botlib/be_interface.c
@@ -140,8 +140,8 @@ int Export_BotLibSetup(void)
 	bot_developer = LibVarGetValue("bot_developer");
   memset( &botlibglobals, 0, sizeof(botlibglobals) ); // bk001207 - init
 	//initialize byte swapping (litte endian etc.)
-//	Swap_Init();
-	Log_Open("botlib.log");
+	Swap_Init();
+	Log_Open("/dev/null");
 	//
 	botimport.Print(PRT_MESSAGE, "------- BotLib Initialization -------\n");
 	//
