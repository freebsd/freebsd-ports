--- libretro/main.cpp.orig	2020-10-29 23:31:05 UTC
+++ libretro/main.cpp
@@ -148,6 +148,7 @@ static void RetroLog_DoWriteLn(const wxString& fmt)
 	RetroLog_DoWrite(fmt + L"\n");
 }
 
+/*
 static const IConsoleWriter ConsoleWriter_Libretro =
 	{
 		RetroLog_DoWrite,
@@ -160,6 +161,7 @@ static const IConsoleWriter ConsoleWriter_Libretro =
 
 		0, // instance-level indentation (should always be 0)
 };
+*/
 
 static std::vector<const char*> disk_images;
 static int image_index = 0;
@@ -244,9 +246,11 @@ void retro_init(void)
 	if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log))
 	{
 		log_cb = log.log;
+/*
 #if 0
 		Console_SetActiveHandler(ConsoleWriter_Libretro);
 #endif
+*/
 	}
 
 	//	pcsx2 = new Pcsx2App;
