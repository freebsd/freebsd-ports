--- FTGlyphVectorizer.h.orig	Tue Jun 10 13:41:02 2003
+++ FTGlyphVectorizer.h	Tue Jun 10 13:41:07 2003
@@ -76,7 +76,7 @@
     private:
       void add_point( double x, double y );
 
-    friend FTGlyphVectorizer;
+    friend class FTGlyphVectorizer;
     };
 
 protected:
