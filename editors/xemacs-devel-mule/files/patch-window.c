Index: src/window.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/window.c,v
retrieving revision 1.88
retrieving revision 1.89
diff -u -r1.88 -r1.89
--- src/window.c	2005/10/25 11:16:30	1.88
+++ src/window.c	2005/11/18 12:23:57	1.89
@@ -4314,7 +4314,14 @@
       if (NILP (parent))
 	{
 	  if (widthflag)
-	    invalid_operation ("No other window to side of this one", Qunbound);
+	    {
+	      int new_pixsize;
+	      sizep = &CURSIZE (w);
+	      dim = CURCHARSIZE (w);
+	      new_pixsize = inpixels?(*sizep + delta):(dim+delta);
+	      set_window_pixsize (window, new_pixsize, 0, 0);
+	      return;
+	    }
 	  break;
 	}
       if (widthflag
