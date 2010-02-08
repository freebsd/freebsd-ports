--- a/ppc.ld
+++ b/ppc.ld
@@ -79,36 +79,34 @@
   }
   .sbss2          : { *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*) }
   .eh_frame_hdr : { *(.eh_frame_hdr) }
-  .eh_frame       : ONLY_IF_RO { KEEP (*(.eh_frame)) }
-  .gcc_except_table   : ONLY_IF_RO { *(.gcc_except_table .gcc_except_table.*) }
   /* Adjust the address for the data segment.  We want to adjust up to
      the same address within the page on the next page up.  */
   . = ALIGN (0x10000) - ((0x10000 - .) & (0x10000 - 1)); . = DATA_SEGMENT_ALIGN (0x10000, 0x1000);
   /* Exception handling  */
-  .eh_frame       : ONLY_IF_RW { KEEP (*(.eh_frame)) }
-  .gcc_except_table   : ONLY_IF_RW { *(.gcc_except_table .gcc_except_table.*) }
+  .eh_frame       : { KEEP (*(.eh_frame)) }
+  .gcc_except_table   : { *(.gcc_except_table .gcc_except_table.*) }
   /* Thread Local Storage sections  */
   .tdata	  : { *(.tdata .tdata.* .gnu.linkonce.td.*) }
   .tbss		  : { *(.tbss .tbss.* .gnu.linkonce.tb.*) *(.tcommon) }
   .preinit_array     :
   {
-    PROVIDE_HIDDEN (__preinit_array_start = .);
+    PROVIDE (__preinit_array_start = .);
     KEEP (*(.preinit_array))
-    PROVIDE_HIDDEN (__preinit_array_end = .);
+    PROVIDE (__preinit_array_end = .);
   }
   .init_array     :
   {
-     PROVIDE_HIDDEN (__init_array_start = .);
+     PROVIDE (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array))
-     PROVIDE_HIDDEN (__init_array_end = .);
+     PROVIDE(__init_array_end = .);
   }
   .fini_array     :
   {
-    PROVIDE_HIDDEN (__fini_array_start = .);
+    PROVIDE (__fini_array_start = .);
     KEEP (*(.fini_array))
     KEEP (*(SORT(.fini_array.*)))
-    PROVIDE_HIDDEN (__fini_array_end = .);
+    PROVIDE (__fini_array_end = .);
   }
   .ctors          :
   {
@@ -142,9 +140,8 @@
   .got1           : { *(.got1) }
   .got2           : { *(.got2) }
   .dynamic        : { *(.dynamic) }
-  .got            : SPECIAL { *(.got) }
-  . = DATA_SEGMENT_RELRO_END (0, .);
-  .plt            : SPECIAL { *(.plt) }
+  .got            : { *(.got) }
+  .plt            : { *(.plt) }
   .data           :
   {
     *(.data .data.* .gnu.linkonce.d.*)
@@ -152,7 +149,7 @@
     SORT(CONSTRUCTORS)
   }
   .data1          : { *(.data1) }
-  .got            : SPECIAL { *(.got) }
+  .got            : { *(.got) }
   /* We want the small data sections together, so single-instruction offsets
      can access them all, and initialized data all before uninitialized, so
      we can shorten the on-disk segment size.  */
@@ -171,7 +168,7 @@
     *(.scommon)
     PROVIDE (__sbss_end = .); PROVIDE (___sbss_end = .);
   }
-  .plt            : SPECIAL { *(.plt) }
+  .plt            : { *(.plt) }
   .bss            :
   {
    *(.dynbss)
