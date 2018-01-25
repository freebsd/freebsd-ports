--- binutils-2.26/bfd/elflink.c.orig	2018-01-25 17:15:39.513265000 +0300
+++ binutils-2.26/bfd/elflink.c	2018-01-25 17:16:03.663426000 +0300
@@ -5058,7 +5058,7 @@
   len = strlen (name);
   copy = (char *) bfd_alloc (abfd, len);
   if (copy == NULL)
-    return (struct elf_link_hash_entry *) 0 - 1;
+    return (struct elf_link_hash_entry *)(intptr_t)-1;
 
   first = p - name + 1;
   memcpy (copy, name, first);
@@ -5156,7 +5156,7 @@
 	    }
 
 	  h = archive_symbol_lookup (abfd, info, symdef->name);
-	  if (h == (struct elf_link_hash_entry *) 0 - 1)
+	  if (h == (struct elf_link_hash_entry *)(intptr_t)-1)
 	    goto error_return;
 
 	  if (h == NULL)
