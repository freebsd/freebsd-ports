--- modules/modgraph.c.orig	2003-08-21 01:11:03 UTC
+++ modules/modgraph.c
@@ -183,7 +183,7 @@ void	dump_assembly(int fd, elfshblk_t *b
   else
     {
       name = elfsh_reverse_metasym(world.current, blk->vaddr, &off);
-      dprintf(fd, "%s_%08x", name, off);
+      _dprintf(fd, "%s_%08x", name, off);
 
       }
   free(buffer);
