$FreeBSD$

--- ShowTable.pm.orig	Sun Mar  2 23:04:50 1997
+++ ShowTable.pm	Fri Dec 27 16:25:33 2002
@@ -721,7 +721,7 @@
 
 S<  >B<ShowHTMLTable> I<\@titles>, I<\@types>, I<\@widths>, I<\&row_sub>
 [, I<\&fmt_sub> [, I<$max_width> [, I<\%URL_Keys> [, I<$no_escape> 
-[, I<\@title_formats [, I<\@data_formats [, I<$table_attrs> ] ] ] ] ] ] ];
+[, I<\@title_formats> [, I<\@data_formats> [, I<$table_attrs> ] ] ] ] ] ] ];
 
 The B<ShowHTMLTable> displays one or more rows of columns of data using
 the HTML C<\<TABLE\>> feature.  In addition to the usual parameter arguments
