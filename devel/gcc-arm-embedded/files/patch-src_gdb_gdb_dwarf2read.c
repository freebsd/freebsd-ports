--- src/gdb/gdb/dwarf2read.c.orig	2018-01-25 13:10:17.113384000 +0300
+++ src/gdb/gdb/dwarf2read.c	2018-01-25 13:11:33.355566000 +0300
@@ -23105,7 +23105,7 @@
 	  }
 	  break;
 
-        case DW_MACINFO_vendor_ext:
+        case DW_MACRO_hi_user:
 	  if (!section_is_gnu)
 	    {
 	      unsigned int bytes_read;
@@ -23281,7 +23281,7 @@
 	  mac_ptr += offset_size;
 	  break;
 
-	case DW_MACINFO_vendor_ext:
+	case DW_MACRO_hi_user:
 	  /* Only skip the data by MAC_PTR.  */
 	  if (!section_is_gnu)
 	    {
