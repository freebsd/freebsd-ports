RCS file: /cvs/src/src/ld/scripttempl/elf.sc,v
retrieving revision 1.81
retrieving revision 1.82
diff -u -r1.81 -r1.82
--- ld/scripttempl/elf.sc	2007/06/29 16:29:17	1.81
+++ ld/scripttempl/elf.sc	2007/07/10 04:53:13	1.82
@@ -124,7 +124,7 @@
 DYNAMIC=".dynamic      ${RELOCATING-0} : { *(.dynamic) }"
 RODATA=".rodata       ${RELOCATING-0} : { *(.rodata${RELOCATING+ .rodata.* .gnu.linkonce.r.*}) }"
 DATARELRO=".data.rel.ro : { *(.data.rel.ro.local* .gnu.linkonce.d.rel.ro.local.*) *(.data.rel.ro* .gnu.linkonce.d.rel.ro.*) }"
-STACKNOTE="/DISCARD/ : { *(.note.GNU-stack) }"
+DISCARDED="/DISCARD/ : { *(.note.GNU-stack) *(.gnu_debuglink) }"
 if test -z "${NO_SMALL_DATA}"; then
   SBSS=".sbss         ${RELOCATING-0} :
   {
@@ -518,6 +518,6 @@
   ${ATTRS_SECTIONS}
   ${OTHER_SECTIONS}
   ${RELOCATING+${OTHER_SYMBOLS}}
-  ${RELOCATING+${STACKNOTE}}
+  ${RELOCATING+${DISCARDED}}
 }
 EOF
