--- gcc/cccp.c.orig	1999/08/26 09:26:39	1.1.1.2
+++ gcc/cccp.c	1999/08/27 11:02:42	1.3
@@ -5096,6 +5096,7 @@
   register struct file_name_map *map;
   register char *from;
 
+#ifndef FREEBSD_NATIVE
   if (searchptr)
     {
       if (! searchptr->got_name_map)
@@ -5110,6 +5111,7 @@
 	if (! strcmp (map->map_from, from))
 	  return map->map_to;
     }
+#endif
 
   from = base_name (filename);
 
@@ -5124,9 +5126,11 @@
       bcopy (filename, dir, from - filename);
       dir[from - filename] = '\0';
 
+#ifndef FREEBSD_NATIVE
       for (map = read_name_map (dir); map; map = map->map_next)
 	if (! strcmp (map->map_from, from))
 	  return map->map_to;
+#endif
     }
 
   return filename;
