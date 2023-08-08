--- src/main.c.orig	2023-05-17 05:45:51 UTC
+++ src/main.c
@@ -575,7 +575,7 @@ main(int argc, char **argv)
 
 	run_after_load = false;
 
-	char *base_path = SDL_GetBasePath();
+	char *base_path = "%%PREFIX%%/share/x16-emulator/";
 
 	// This causes the emulator to load ROM data from the executable's directory when
 	// no ROM file is specified on the command line.
