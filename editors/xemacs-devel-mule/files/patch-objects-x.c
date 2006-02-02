Index: src/objects-x.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/objects-x.c,v
retrieving revision 1.30
retrieving revision 1.36
diff -u -r1.30 -r1.36
--- src/objects-x.c	2005/11/26 18:25:03	1.30
+++ src/objects-x.c	2006/01/20 17:50:46	1.36
@@ -693,8 +693,9 @@
   return result;
 }
 
-/* Unbounded, for sufficiently small values of infinity... */
-#define MAX_FONT_COUNT 5000
+/* XListFonts doesn't allocate memory unconditionally based on this. (For
+   XFree86 in 2005, at least. */
+#define MAX_FONT_COUNT INT_MAX
 
 static Extbyte *
 truename_via_XListFonts (Display *dpy, Extbyte *font_name)
@@ -807,7 +808,8 @@
       FcChar8 *res = FcNameUnparse (FONT_INSTANCE_X_XFTFONT (f)->pattern);
       if (res)
 	{
-	  FONT_INSTANCE_TRUENAME (f) = make_string (res, strlen (res));
+	  FONT_INSTANCE_TRUENAME (f) = 
+	    build_ext_string (res, Qxft_font_name_encoding); 
 	  free (res);
 	  return FONT_INSTANCE_TRUENAME (f);
 	}
@@ -1175,7 +1177,7 @@
   Extbyte **names;
   int count = 0;
   const Extbyte *patternext;
-  Lisp_Object result = Qunbound;
+  Lisp_Object result = Qnil;
   int i;
 
   /* #### with Xft need to handle second stage here -- sjt
@@ -1441,7 +1443,8 @@
       if (x_font_spec_matches_charset (XDEVICE (device), charset,
 				       intname, Qnil, 0, -1, 0))
 	{
-	  result = make_string (intname, intlen);
+	  result = build_ext_string ((const Extbyte *) intname, 
+				     Qx_font_name_encoding); 
 	  break;
 	}
     }
