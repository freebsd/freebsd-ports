--- libdw/dwarf_getsrclines.c.orig	2016-12-25 13:36:55 UTC
+++ libdw/dwarf_getsrclines.c
@@ -273,7 +273,7 @@ read_srclines (Dwarf *dbg,
   /* Remember array with the standard opcode length (-1 to account for
      the opcode with value zero not being mentioned).  */
   const uint8_t *standard_opcode_lengths = linep - 1;
-  if (unlikely (lineendp - linep < opcode_base - 1))
+  if (unlikely (lineendp - linep < (ptrdiff_t)opcode_base - 1))
     goto invalid_data;
   linep += opcode_base - 1;
 
