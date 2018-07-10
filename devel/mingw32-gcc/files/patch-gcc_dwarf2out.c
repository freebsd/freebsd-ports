--- gcc/dwarf2out.c.orig	2013-03-21 21:24:47 UTC
+++ gcc/dwarf2out.c
@@ -5268,8 +5268,8 @@ print_die (dw_die_ref die, FILE *outfile
 	  fprintf (outfile, HOST_WIDE_INT_PRINT_UNSIGNED, AT_unsigned (a));
 	  break;
 	case dw_val_class_const_double:
-	  fprintf (outfile, "constant ("HOST_WIDE_INT_PRINT_DEC","\
-			    HOST_WIDE_INT_PRINT_UNSIGNED")",
+	  fprintf (outfile, "constant (" HOST_WIDE_INT_PRINT_DEC ","\
+			    HOST_WIDE_INT_PRINT_UNSIGNED ")",
 		   a->dw_attr_val.v.val_double.high,
 		   a->dw_attr_val.v.val_double.low);
 	  break;
