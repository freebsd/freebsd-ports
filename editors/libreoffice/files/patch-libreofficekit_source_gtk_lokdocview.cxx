--- libreofficekit/source/gtk/lokdocview.cxx.orig	2018-01-31 18:56:05.312032000 +0300
+++ libreofficekit/source/gtk/lokdocview.cxx	2018-01-31 18:56:30.075522000 +0300
@@ -3218,6 +3218,7 @@
                      G_TYPE_STRING);
 
     /**
+     * LOKDocView::ruler:
      * The key ruler related properties on change are reported by this.
      *
      * The payload format is:
@@ -3244,6 +3245,7 @@
                      G_TYPE_STRING);
 
     /**
+     * LOKDocView::invalidate-header:
      * The column/row header is no more valid because of a column/row insertion
      * or a similar event. Clients must query a new column/row header set.
      *
