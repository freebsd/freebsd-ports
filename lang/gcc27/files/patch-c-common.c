--- c-common.c.orig	Thu Oct 19 16:18:29 1995
+++ c-common.c	Mon Mar 20 13:29:10 2000
@@ -536,6 +536,7 @@
 	    int format_num;
 	    int first_arg_num;
 	    int is_scan;
+	    int null_format_ok;
 	    tree argument;
 	    int arg_num;
 	
@@ -550,15 +551,30 @@
 		&& (!strcmp (IDENTIFIER_POINTER (format_type), "printf")
 		    || !strcmp (IDENTIFIER_POINTER (format_type),
 				"__printf__")))
-	      is_scan = 0;
+	      {
+		is_scan = 0;
+		null_format_ok = 0;
+	      }
+	    else if (TREE_CODE (format_type) == IDENTIFIER_NODE
+		     && (!strcmp (IDENTIFIER_POINTER (format_type), "printf0")
+			 || !strcmp (IDENTIFIER_POINTER (format_type),
+				     "__printf0__")))
+	      {
+		is_scan = 0;
+		null_format_ok = 1;
+	      }
 	    else if (TREE_CODE (format_type) == IDENTIFIER_NODE
 		     && (!strcmp (IDENTIFIER_POINTER (format_type), "scanf")
 			 || !strcmp (IDENTIFIER_POINTER (format_type),
 				     "__scanf__")))
-	      is_scan = 1;
+	      {
+		is_scan = 1;
+		null_format_ok = 0;
+	      }
 	    else
 	      {
-		error ("unrecognized format specifier for `%s'");
+		error_with_decl (decl,
+		         "unrecognized format specifier for `%s'");
 		continue;
 	      }
 
@@ -625,7 +641,8 @@
 
 	    record_function_format (DECL_NAME (decl),
 				    DECL_ASSEMBLER_NAME (decl),
-				    is_scan, format_num, first_arg_num);
+				    is_scan, null_format_ok, format_num,
+				    first_arg_num);
 	    break;
 	  }
 
@@ -696,6 +713,11 @@
 } format_char_info;
 
 static format_char_info print_char_table[] = {
+/* FreeBSD kernel extensions.  */
+  { "D",	1,	T_C,	NULL,	NULL,	NULL,	NULL,	"-wp"		},
+  { "b",	1,	T_C,	NULL,	NULL,	NULL,	NULL,	"-wp"		},
+  { "rz",	0,	T_I,	T_I,	T_L,	NULL,	NULL,	"-wp0 +#"	},
+#define unextended_print_char_table	(print_char_table + 3)
   { "di",	0,	T_I,	T_I,	T_L,	T_LL,	T_LL,	"-wp0 +"	},
   { "oxX",	0,	T_UI,	T_UI,	T_UL,	T_ULL,	T_ULL,	"-wp0#"		},
   { "u",	0,	T_UI,	T_UI,	T_UL,	T_ULL,	T_ULL,	"-wp0"		},
@@ -730,6 +752,7 @@
   tree name;			/* identifier such as "printf" */
   tree assembler_name;		/* optional mangled identifier (for C++) */
   int is_scan;			/* TRUE if *scanf */
+  int null_format_ok;		/* TRUE if the format string may be NULL */
   int format_num;		/* number of format argument */
   int first_arg_num;		/* number of first arg (zero for varargs) */
 } function_format_info;
@@ -748,15 +771,15 @@
 void
 init_function_format_info ()
 {
-  record_function_format (get_identifier ("printf"), NULL_TREE, 0, 1, 2);
-  record_function_format (get_identifier ("fprintf"), NULL_TREE, 0, 2, 3);
-  record_function_format (get_identifier ("sprintf"), NULL_TREE, 0, 2, 3);
-  record_function_format (get_identifier ("scanf"), NULL_TREE, 1, 1, 2);
-  record_function_format (get_identifier ("fscanf"), NULL_TREE, 1, 2, 3);
-  record_function_format (get_identifier ("sscanf"), NULL_TREE, 1, 2, 3);
-  record_function_format (get_identifier ("vprintf"), NULL_TREE, 0, 1, 0);
-  record_function_format (get_identifier ("vfprintf"), NULL_TREE, 0, 2, 0);
-  record_function_format (get_identifier ("vsprintf"), NULL_TREE, 0, 2, 0);
+  record_function_format (get_identifier ("printf"), NULL_TREE, 0, 0, 1, 2);
+  record_function_format (get_identifier ("fprintf"), NULL_TREE, 0, 0, 2, 3);
+  record_function_format (get_identifier ("sprintf"), NULL_TREE, 0, 0, 2, 3);
+  record_function_format (get_identifier ("scanf"), NULL_TREE, 1, 0, 1, 2);
+  record_function_format (get_identifier ("fscanf"), NULL_TREE, 1, 0, 2, 3);
+  record_function_format (get_identifier ("sscanf"), NULL_TREE, 1, 0, 2, 3);
+  record_function_format (get_identifier ("vprintf"), NULL_TREE, 0, 0, 1, 0);
+  record_function_format (get_identifier ("vfprintf"), NULL_TREE, 0, 0, 2, 0);
+  record_function_format (get_identifier ("vsprintf"), NULL_TREE, 0, 0, 2, 0);
 }
 
 /* Record information for argument format checking.  FUNCTION_IDENT is
@@ -769,11 +792,12 @@
    (e.g. for varargs such as vfprintf).  */
 
 void
-record_function_format (name, assembler_name, is_scan,
+record_function_format (name, assembler_name, is_scan, null_format_ok,
 			format_num, first_arg_num)
       tree name;
       tree assembler_name;
       int is_scan;
+      int null_format_ok;
       int format_num;
       int first_arg_num;
 {
@@ -797,6 +821,7 @@
     }
 
   info->is_scan = is_scan;
+  info->null_format_ok = null_format_ok;
   info->format_num = format_num;
   info->first_arg_num = first_arg_num;
 }
@@ -876,7 +901,8 @@
     format_tree = TREE_OPERAND (format_tree, 0); /* strip coercion */
   if (integer_zerop (format_tree))
     {
-      warning ("null format string");
+      if (!info->null_format_ok)
+	warning ("null format string");
       return;
     }
   if (TREE_CODE (format_tree) != ADDR_EXPR)
@@ -1050,11 +1076,12 @@
 		      cur_param = TREE_VALUE (params);
 		      params = TREE_CHAIN (params);
 		      ++arg_num;
+		      /* XXX should we allow unsigned ints here?  */
 		      if (TYPE_MAIN_VARIANT (TREE_TYPE (cur_param))
 			  != integer_type_node)
 		        {
 		          sprintf (message,
-				   "field width is not type int (arg %d)",
+				   "precision is not type int (arg %d)",
 				   arg_num);
 		          warning (message);
 		        }
@@ -1067,6 +1094,56 @@
 		}
 	    }
 	}
+      if (*format_chars == 'b')
+	{
+	  /* There should be an int arg to control the string arg.  */
+	  if (params == 0)
+	    {
+	      warning (tfaff);
+	      return;
+	    }
+	    if (info->first_arg_num != 0)
+	    {
+	      cur_param = TREE_VALUE (params);
+	      params = TREE_CHAIN (params);
+	      ++arg_num;
+	      if ((TYPE_MAIN_VARIANT (TREE_TYPE (cur_param))
+		   != integer_type_node)
+		  &&
+		  (TYPE_MAIN_VARIANT (TREE_TYPE (cur_param))
+		   != unsigned_type_node))
+		{
+		  sprintf (message, "bitmap is not type int (arg %d)",
+			   arg_num);
+		  warning (message);
+		}
+	    }
+	}
+      if (*format_chars == 'D')
+	{
+	  /* There should be an unsigned char * arg before the string arg.  */
+	  if (params == 0)
+	    {
+	      warning (tfaff);
+	      return;
+	    }
+	    if (info->first_arg_num != 0)
+	    {
+	      cur_param = TREE_VALUE (params);
+	      params = TREE_CHAIN (params);
+	      ++arg_num;
+	      cur_type = TREE_TYPE (cur_param);
+	      if (TREE_CODE (cur_type) != POINTER_TYPE
+		  || TYPE_MAIN_VARIANT (TREE_TYPE (cur_type))
+		     != unsigned_char_type_node)
+		{
+		  sprintf (message,
+		      "ethernet address is not type unsigned char * (arg %d)",
+			   arg_num);
+		  warning (message);
+		}
+	    }
+	}
       if (*format_chars == 'h' || *format_chars == 'l' || *format_chars == 'q' ||
 	  *format_chars == 'L')
 	length_char = *format_chars++;
@@ -1094,7 +1171,9 @@
 	  continue;
 	}
       format_chars++;
-      fci = info->is_scan ? scan_char_table : print_char_table;
+      fci = info->is_scan ? scan_char_table
+	    : flag_format_extensions ? print_char_table
+	    : unextended_print_char_table;
       while (fci->format_chars != 0
 	     && index (fci->format_chars, format_char) == 0)
 	  ++fci;
@@ -2048,6 +2127,12 @@
       return real_zerop (expr) ? boolean_false_node : boolean_true_node;
 
     case ADDR_EXPR:
+      /* If we are taking the address of a external decl, it might be zero
+         if it is weak, so we cannot optimize.  */
+      if (TREE_CODE_CLASS (TREE_CODE (TREE_OPERAND (expr, 0))) == 'd'
+          && DECL_EXTERNAL (TREE_OPERAND (expr, 0)))
+        break;
+
       if (TREE_SIDE_EFFECTS (TREE_OPERAND (expr, 0)))
 	return build (COMPOUND_EXPR, boolean_type_node,
 		      TREE_OPERAND (expr, 0), boolean_true_node);
