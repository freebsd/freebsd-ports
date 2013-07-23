--- gdb/gdbtk/generic/gdbtk-hooks.c.orig	2013-07-15 11:47:33.000000000 +0200
+++ gdb/gdbtk/generic/gdbtk-hooks.c	2013-07-15 11:48:41.000000000 +0200
@@ -254,13 +254,13 @@
 	  actual_len = 0;
 	}
       else
-        actual_len = strlen (gdbtk_interp->result);
+        actual_len = strlen (Tcl_GetStringResult(gdbtk_interp));
 
       /* Truncate the string if it is too big for the caller's buffer.  */
       if (actual_len >= sizeof_buf)
 	actual_len = sizeof_buf - 1;
       
-      memcpy (buf, gdbtk_interp->result, actual_len);
+      memcpy (buf, Tcl_GetStringResult(gdbtk_interp), actual_len);
       buf[actual_len] = '\0';
       return actual_len;
     }
@@ -505,11 +505,11 @@
 
   if (result == TCL_OK)
     {
-      return (xstrdup (gdbtk_interp->result));
+      return (xstrdup (Tcl_GetStringResult(gdbtk_interp)));
     }
   else
     {
-      gdbtk_fputs (gdbtk_interp->result, gdb_stdout);
+      gdbtk_fputs (Tcl_GetStringResult(gdbtk_interp), gdb_stdout);
       gdbtk_fputs ("\n", gdb_stdout);
       return (NULL);
     }
@@ -633,7 +633,7 @@
     report_error ();
   free(buf);
 
-  return atoi (gdbtk_interp->result);
+  return atoi (Tcl_GetStringResult(gdbtk_interp));
 }
 
 
@@ -686,7 +686,7 @@
   gdbtk_two_elem_cmd ("gdbtk_tcl_query", buf);
   free(buf);
 
-  val = atol (gdbtk_interp->result);
+  val = atol (Tcl_GetStringResult(gdbtk_interp));
   return val;
 }
 
