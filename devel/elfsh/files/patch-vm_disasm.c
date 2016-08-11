--- vm/disasm.c.orig	2003-08-21 01:11:03 UTC
+++ vm/disasm.c
@@ -82,13 +82,13 @@ u_int		display_instr(int fd, u_int index
   if (world.state.vm_quiet)
     {
       snprintf(buf, sizeof(buf), " %08X %s + %u", vaddr + index, name, nindex);
-      dprintf(fd, "%-40s %-30s ", buf, s);
+      _dprintf(fd, "%-40s %-30s ", buf, s);
     }
   else
     {
       snprintf(buf, sizeof(buf), " %08X [foff: %u] %s + %u", 
 	      vaddr + index, foffset + index, name, nindex);
-      dprintf(fd, "%-60s %-50s ", buf, s);
+      _dprintf(fd, "%-60s %-50s ", buf, s);
     }
   
   /* Print bytes in hexa for this instruction */
@@ -98,10 +98,10 @@ u_int		display_instr(int fd, u_int index
   
   if (!world.state.vm_quiet)
     for (idx_bytes = 0; idx_bytes < ret; idx_bytes++)
-      dprintf(fd, "%c%c ", 
+      _dprintf(fd, "%c%c ", 
 	     base[(buff[index + idx_bytes] >> 4) & 0x0F], 
 	     base[buff[index + idx_bytes] & 0x0F]);
-  dprintf(fd, "\n");
+  _dprintf(fd, "\n");
   return (ret);
 }
 #endif	/* USE_LIBASM */
