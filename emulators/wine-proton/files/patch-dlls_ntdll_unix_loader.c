--- dlls/ntdll/unix/loader.c.orig
+++ dlls/ntdll/unix/loader.c
@@ -1306,7 +1306,7 @@
 
 #ifdef __FreeBSD__
         /* On older FreeBSD versions, l_addr was the absolute load address, now it's the relocation offset. */
-        if (!dlsym(RTLD_DEFAULT, "_rtld_version_laddr_offset"))
+        if (offsetof(struct link_map, l_addr) == 0)
             if (!get_relocbase(map->l_addr, &relocbase)) return;
 #endif
         switch (dyn->d_tag)
