
$FreeBSD$

--- gdb/rs6000-tdep.c
+++ gdb/rs6000-tdep.c
@@ -3290,6 +3290,7 @@
     case GDB_OSABI_NETBSD_ELF:
     case GDB_OSABI_UNKNOWN:
     case GDB_OSABI_LINUX:
+    case GDB_OSABI_FREEBSD_ELF:
       set_gdbarch_unwind_pc (gdbarch, rs6000_unwind_pc);
       frame_unwind_append_sniffer (gdbarch, rs6000_frame_sniffer);
       set_gdbarch_unwind_dummy_id (gdbarch, rs6000_unwind_dummy_id);
