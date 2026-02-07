--- src/cdrom/freebsd/SDL_syscdrom.c.orig	2012-03-14 08:36:58.000000000 +0100
+++ src/cdrom/freebsd/SDL_syscdrom.c	2012-03-14 08:36:11.000000000 +0100
@@ -188,7 +188,7 @@
 			char *insert;
 			exists = 1;
 			for ( j=checklist[i][1]; exists; ++j ) {
-				SDL_snprintf(drive, SDL_arraysize(drive), "/dev/%sc", &checklist[i][3]);
+				SDL_snprintf(drive, SDL_arraysize(drive), "/dev/%s", &checklist[i][3]);
 				insert = SDL_strchr(drive, '?');
 				if ( insert != NULL ) {
 					*insert = j;
