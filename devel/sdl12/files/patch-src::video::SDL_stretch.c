
$FreeBSD$

--- src/video/SDL_stretch.c	2003/07/14 18:17:21	1.1
+++ src/video/SDL_stretch.c	2003/07/14 18:18:39
@@ -261,9 +261,9 @@
 			break;
 		    default:
 #ifdef __GNUC__
-			__asm__ __volatile__ ("
-				call _copy_row
-			"
+			__asm__ __volatile__ (""
+			"	call _copy_row"
+			""
 			: "=&D" (u1), "=&S" (u2)
 			: "0" (dstp), "1" (srcp)
 			: "memory" );
