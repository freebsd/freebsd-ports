
$FreeBSD$

--- src/dispnew.c.orig
+++ src/dispnew.c
@@ -1256,7 +1256,7 @@
 /* Copy glyph row structure FROM to glyph row structure TO, except
    that glyph pointers in the structures are left unchanged.  */
 
-INLINE void
+static INLINE void
 copy_row_except_pointers (to, from)
      struct glyph_row *to, *from;
 {
