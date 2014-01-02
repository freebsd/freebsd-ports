This patch is taken from upstream repository r114482.


$FreeBSD$

--- src/xdisp.c.orig
+++ src/xdisp.c
@@ -6870,6 +6870,7 @@
 	}
     }
 
+#ifdef HAVE_WINDOW_SYSTEM
   /* Adjust face id for a multibyte character.  There are no multibyte
      character in unibyte text.  */
   if ((it->what == IT_CHARACTER || it->what == IT_COMPOSITION)
@@ -6910,6 +6911,7 @@
 	  it->face_id = FACE_FOR_CHAR (it->f, face, c, pos, it->string);
 	}
     }
+#endif	/* HAVE_WINDOW_SYSTEM */
 
  done:
   /* Is this character the last one of a run of characters with
