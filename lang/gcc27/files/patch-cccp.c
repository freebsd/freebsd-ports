--- cccp.c.orig	Thu Oct 26 15:07:26 1995
+++ cccp.c	Mon Mar 20 13:29:10 2000
@@ -4923,6 +4923,7 @@
   register char *from;
   char *p, *dir;
 
+#ifndef FREEBSD_NATIVE
   if (searchptr && ! searchptr->got_name_map)
     {
       searchptr->name_map = read_name_map (searchptr->fname
@@ -4945,6 +4946,7 @@
 	    }
 	}
     }
+#endif
 
   /* Try to find a mapping file for the particular directory we are
      looking in.  Thus #include <sys/types.h> will look up sys/types.h
@@ -4981,9 +4983,11 @@
       dir[p - filename] = '\0';
       from = p + 1;
     }
+#ifndef FREEBSD_NATIVE
   for (map = read_name_map (dir); map; map = map->map_next)
     if (! strcmp (map->map_from, from))
       return open (map->map_to, O_RDONLY, 0666);
+#endif
 
   return open (filename, O_RDONLY, 0666);
 }
