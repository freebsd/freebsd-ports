--- gdb/symfile.c	Tue Feb 26 17:40:36 2002
+++ gdb/symfile.c	Wed May 29 11:10:17 2002
@@ -1546,11 +1546,7 @@
       char *val = sect_opts[i].value;
       char *sec = sect_opts[i].name;
  
-      val = sect_opts[i].value;
-      if (val[0] == '0' && val[1] == 'x')
-	addr = strtoul (val+2, NULL, 16);
-      else
-	addr = strtoul (val, NULL, 10);
+      addr = parse_and_eval_address(val);
 
       /* Here we store the section offsets in the order they were
          entered on the command line. */
