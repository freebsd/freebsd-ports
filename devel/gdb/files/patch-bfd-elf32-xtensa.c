--- bfd/elf32-xtensa.c.orig	2013-03-07 10:08:58.000000000 +0100
+++ bfd/elf32-xtensa.c	2013-03-07 10:11:40.000000000 +0100
@@ -6075,7 +6075,7 @@
       release_internal_relocs (sec_cache->sec, sec_cache->relocs);
       if (sec_cache->ptbl)
 	free (sec_cache->ptbl);
-      memset (sec_cache, 0, sizeof (sec_cache));
+      memset (sec_cache, 0, sizeof (*sec_cache));
     }
 }
 
@@ -6117,7 +6117,7 @@
 
   /* Fill in the new section cache.  */
   clear_section_cache (sec_cache);
-  memset (sec_cache, 0, sizeof (sec_cache));
+  memset (sec_cache, 0, sizeof (*sec_cache));
 
   sec_cache->sec = sec;
   sec_cache->contents = contents;
