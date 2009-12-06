Index: qemu/osdep.c
@@ -179,7 +179,9 @@
         }
         unlink(phys_ram_file);
     }
+#endif /* !(__OpenBSD__ || __FreeBSD__ || __DragonFly__) */
     size = (size + 4095) & ~4095;
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
     ftruncate(phys_ram_fd, phys_ram_size + size);
 #endif /* !(__OpenBSD__ || __FreeBSD__ || __DragonFly__) */
     ptr = mmap(NULL,
