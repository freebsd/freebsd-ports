--- a/ppc.ld
+++ b/ppc.ld
@@ -99,7 +99,7 @@ SECTIONS
      PROVIDE (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array))
-     PROVIDE (__init_array_end = .);
+     PROVIDE(__init_array_end = .);
   }
   .fini_array     :
   {
@@ -140,9 +140,8 @@ SECTIONS
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
@@ -150,7 +149,7 @@ SECTIONS
     SORT(CONSTRUCTORS)
   }
   .data1          : { *(.data1) }
-  .got            : SPECIAL { *(.got) }
+  .got            : { *(.got) }
   /* We want the small data sections together, so single-instruction offsets
      can access them all, and initialized data all before uninitialized, so
      we can shorten the on-disk segment size.  */
@@ -169,7 +168,7 @@ SECTIONS
     *(.scommon)
     PROVIDE (__sbss_end = .); PROVIDE (___sbss_end = .);
   }
-  .plt            : SPECIAL { *(.plt) }
+  .plt            : { *(.plt) }
   .bss            :
   {
    *(.dynbss)
