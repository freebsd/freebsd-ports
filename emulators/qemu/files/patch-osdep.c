Index: qemu/osdep.c
@@ -179,13 +179,15 @@ static void *kqemu_vmalloc(size_t size)
         }
         unlink(phys_ram_file);
     }
+#endif /* !(__OpenBSD__ || __FreeBSD__ || __DragonFly__) */
     size = (size + 4095) & ~4095;
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
     ftruncate(phys_ram_fd, phys_ram_size + size);
 #endif /* !(__OpenBSD__ || __FreeBSD__ || __DragonFly__) */
     ptr = mmap(NULL,
                size,
                PROT_WRITE | PROT_READ, map_anon | MAP_SHARED,
-               phys_ram_fd, phys_ram_size);
+               phys_ram_fd, map_anon ? 0 : phys_ram_size);
     if (ptr == MAP_FAILED) {
         fprintf(stderr, "Could not map physical memory\n");
         exit(1);
