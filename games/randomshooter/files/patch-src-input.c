--- src/input.c.orig	2008-02-23 12:14:38.000000000 +0300
+++ src/input.c	2008-02-27 23:53:35.000000000 +0300
@@ -170,7 +170,7 @@
 {
 	char *name = (char *)malloc(25);
 
-	strncpy(name, SDL_GetKeyName(inputValue), 24);
+	strncpy(name, SDL_GetKeyName((SDLKey)inputValue), 24);
 
 	if (strcmp(name, "unknown key") == 0)
 	{
