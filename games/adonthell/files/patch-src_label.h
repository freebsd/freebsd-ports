--- src/label.h.orig	2005-04-16 17:56:32.000000000 +0000
+++ src/label.h
@@ -90,7 +90,7 @@ public :
     /**
        Get the text in string
     */
-    const string text_string () const;
+    const string & text_string () const;
 
 
     /**
