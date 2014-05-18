--- src/memory.c.orig	Sun Dec  7 18:01:46 2003
+++ src/memory.c	Sun Dec  7 18:01:50 2003
@@ -22,6 +22,7 @@
 {
 	if ((base_memory = (char *)malloc((size_t)MEMSIZE)) == NULL)
 		error(FATALERR, "can't allocate memory");
+	memset(base_memory, NULL, (size_t)MEMSIZE);
 	top_memory = base_memory + RoundDown(MEMSIZE);
 
 	lim_temp = top_string = base_memory;

