
$FreeBSD$

--- erts/emulator/hipe/hipe_x86.c.orig
+++ erts/emulator/hipe/hipe_x86.c
@@ -106,7 +106,7 @@
 	abort();
     map_start = mmap(map_hint, map_bytes,
 		     PROT_EXEC|PROT_READ|PROT_WRITE,
-		     MAP_PRIVATE|MAP_ANONYMOUS
+		     MAP_PRIVATE|MAP_ANON
 #ifdef __x86_64__
 		     |MAP_32BIT
 #endif
