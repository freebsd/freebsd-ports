--- src/gdb/gdb/dwarf2read.c.orig	2019-10-26 00:03:38 UTC
+++ src/gdb/gdb/dwarf2read.c
@@ -24621,7 +24621,7 @@ dwarf_decode_macro_bytes (struct dwarf2_cu *cu,
 	  }
 	  break;
 
-        case DW_MACINFO_vendor_ext:
+        case DW_MACRO_hi_user:
 	  if (!section_is_gnu)
 	    {
 	      unsigned int bytes_read;
@@ -24802,7 +24802,7 @@ dwarf_decode_macros (struct dwarf2_cu *cu, unsigned in
 	  mac_ptr += offset_size;
 	  break;
 
-	case DW_MACINFO_vendor_ext:
+	case DW_MACRO_hi_user:
 	  /* Only skip the data by MAC_PTR.  */
 	  if (!section_is_gnu)
 	    {
