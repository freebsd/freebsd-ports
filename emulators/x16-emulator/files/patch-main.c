--- main.c.orig	2020-01-22 19:56:11 UTC
+++ main.c
@@ -442,7 +442,7 @@ main(int argc, char **argv)
 
 	run_after_load = false;
 
-	char *base_path = SDL_GetBasePath();
+	char *base_path = "%%PREFIX%%/share/x16-emulator/";
 
 	// This causes the emulator to load ROM data from the executable's directory when
 	// no ROM file is specified on the command line.
