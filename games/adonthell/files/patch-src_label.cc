--- src/label.cc.orig	2008-05-29 18:42:50.000000000 +0000
+++ src/label.cc
@@ -645,7 +645,7 @@ void label::cursor_previous ()
 }
 
 
-const string label::text_string () const
+const string & label::text_string () const
 {
     return my_text_;  
 }
