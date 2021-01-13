--- src/gdb/gdb/dwarf2/macro.c.orig	2021-01-11 21:34:03.097341000 +0300
+++ src/gdb/gdb/dwarf2/macro.c	2021-01-11 21:37:13.156194000 +0300
@@ -678,7 +678,7 @@
 	  }
 	  break;
 
-        case DW_MACINFO_vendor_ext:
+        case DW_MACRO_hi_user:
 	  if (!section_is_gnu)
 	    {
 	      unsigned int bytes_read;
@@ -823,7 +823,7 @@
 	  mac_ptr += offset_size;
 	  break;
 
-	case DW_MACINFO_vendor_ext:
+	case DW_MACRO_hi_user:
 	  /* Only skip the data by MAC_PTR.  */
 	  if (!section_is_gnu)
 	    {
