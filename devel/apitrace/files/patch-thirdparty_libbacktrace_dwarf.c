--- thirdparty/libbacktrace/dwarf.c.orig	2017-10-13 17:18:18 UTC
+++ thirdparty/libbacktrace/dwarf.c
@@ -768,21 +768,27 @@ read_attribute (enum dwarf_form form, st
 			       version, addrsize, dwarf_str, dwarf_str_size,
 			       val);
       }
+#if defined(DW_FORM_sec_offset) // not defined on 10
     case DW_FORM_sec_offset:
       val->encoding = ATTR_VAL_REF_SECTION;
       val->u.uint = read_offset (buf, is_dwarf64);
       return 1;
+#endif
+#if defined(DW_FORM_exprloc) // not defined on 10
     case DW_FORM_exprloc:
       val->encoding = ATTR_VAL_EXPR;
       return advance (buf, read_uleb128 (buf));
+#endif
     case DW_FORM_flag_present:
       val->encoding = ATTR_VAL_UINT;
       val->u.uint = 1;
       return 1;
+#if defined(DW_FORM_ref_sig8) // not defined on 10
     case DW_FORM_ref_sig8:
       val->encoding = ATTR_VAL_REF_TYPE;
       val->u.uint = read_uint64 (buf);
       return 1;
+#endif
     case DW_FORM_GNU_addr_index:
       val->encoding = ATTR_VAL_REF_SECTION;
       val->u.uint = read_uleb128 (buf);
@@ -1314,7 +1320,7 @@ find_address_ranges (struct backtrace_st
 		  highpc_is_relative = 1;
 		}
 	      break;
-
+#if defined(DW_AT_ranges) // not defined on 10
 	    case DW_AT_ranges:
 	      if (val.encoding == ATTR_VAL_UINT
 		  || val.encoding == ATTR_VAL_REF_SECTION)
@@ -1323,7 +1329,7 @@ find_address_ranges (struct backtrace_st
 		  have_ranges = 1;
 		}
 	      break;
-
+#endif
 	    case DW_AT_stmt_list:
 	      if (abbrev->tag == DW_TAG_compile_unit
 		  && (val.encoding == ATTR_VAL_UINT
@@ -1851,10 +1857,6 @@ read_line_program (struct backtrace_stat
 		  }
 	      }
 	      break;
-	    case DW_LNE_set_discriminator:
-	      /* We don't care about discriminators.  */
-	      read_uleb128 (line_buf);
-	      break;
 	    default:
 	      if (!advance (line_buf, len - 1))
 		return 0;
@@ -2108,16 +2110,24 @@ read_referenced_name (struct dwarf_data 
 	  if (val.encoding == ATTR_VAL_STRING)
 	    ret = val.u.string;
 	  break;
-
+#if defined(DW_AT_linkage_name)
 	case DW_AT_linkage_name:
+#endif
+#if defined(DW_AT_MIPS_linkage_name)
 	case DW_AT_MIPS_linkage_name:
+#endif
+#if defined(DW_AT_linkage_name) || defined(DW_AT_MIPS_linkage_name)
 	  if (val.encoding == ATTR_VAL_STRING)
 	    return val.u.string;
 	  break;
-
+#endif
 	case DW_AT_specification:
 	  if (abbrev->attrs[i].form == DW_FORM_ref_addr
+#if defined(DW_FORM_ref_sig8) // not defined on 10
 	      || abbrev->attrs[i].form == DW_FORM_ref_sig8)
+#else
+	      || 0) // not defined
+#endif
 	    {
 	      /* This refers to a specification defined in some other
 		 compilation unit.  We can handle this case if we
@@ -2325,6 +2335,7 @@ read_function_entry (struct backtrace_st
 	    {
 	      switch (abbrev->attrs[i].name)
 		{
+#if defined(DW_AT_call_file)
 		case DW_AT_call_file:
 		  if (val.encoding == ATTR_VAL_UINT)
 		    {
@@ -2344,16 +2355,21 @@ read_function_entry (struct backtrace_st
 			}
 		    }
 		  break;
-
+#endif
+#if defined(DW_AT_call_line)
 		case DW_AT_call_line:
 		  if (val.encoding == ATTR_VAL_UINT)
 		    function->caller_lineno = val.u.uint;
 		  break;
-
+#endif
 		case DW_AT_abstract_origin:
 		case DW_AT_specification:
 		  if (abbrev->attrs[i].form == DW_FORM_ref_addr
+#if defined(DW_FORM_ref_sig8) // not defined on 10
 		      || abbrev->attrs[i].form == DW_FORM_ref_sig8)
+#else
+		      || 0) // not defined
+#endif
 		    {
 		      /* This refers to an abstract origin defined in
 			 some other compilation unit.  We can handle
@@ -2383,13 +2399,17 @@ read_function_entry (struct backtrace_st
 			function->name = val.u.string;
 		    }
 		  break;
-
+#if defined(DW_AT_linkage_name)
 		case DW_AT_linkage_name:
+#endif
+#if defined(DW_AT_MIPS_linkage_name)
 		case DW_AT_MIPS_linkage_name:
+#endif
+#if defined(DW_AT_linkage_name) || defined(DW_AT_MIPS_linkage_name)
 		  if (val.encoding == ATTR_VAL_STRING)
 		    function->name = val.u.string;
 		  break;
-
+#endif
 		case DW_AT_low_pc:
 		  if (val.encoding == ATTR_VAL_ADDRESS)
 		    {
@@ -2411,7 +2431,7 @@ read_function_entry (struct backtrace_st
 		      highpc_is_relative = 1;
 		    }
 		  break;
-
+#if defined(DW_AT_ranges) // not defined on 10
 		case DW_AT_ranges:
 		  if (val.encoding == ATTR_VAL_UINT
 		      || val.encoding == ATTR_VAL_REF_SECTION)
@@ -2420,7 +2440,7 @@ read_function_entry (struct backtrace_st
 		      have_ranges = 1;
 		    }
 		  break;
-
+#endif
 		default:
 		  break;
 		}
