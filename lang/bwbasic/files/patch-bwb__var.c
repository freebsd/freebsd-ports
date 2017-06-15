--- bwb_var.c.orig	2017-01-19 00:10:00 UTC
+++ bwb_var.c
@@ -124,7 +124,7 @@ bwb_COMMON(LineType * l)
          {
             /* COMMON A(,,) : DIM A( 5, 10, 20 ) */
             dimensions++;
-            while( line_skip_comma(l) );
+            while( line_skip_comma(l) )
             {
                dimensions++;
             }
@@ -2640,7 +2640,7 @@ bwb_OPTION_USING(LineType * l)
    */
    n = bwb_strlen( tbuf );
    /* PAD RIGHT with NUL */
-   for( i = n; n < 12; i++ )
+   for( i = n; i < 12; i++ )
    {
       tbuf[ i ] = BasicNulChar;
    }
