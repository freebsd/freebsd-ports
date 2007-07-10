--- ext/tk/lib/tkextlib/tile/dialog.rb.orig	Tue Feb 13 02:01:19 2007
+++ ext/tk/lib/tkextlib/tile/dialog.rb	Fri May 25 20:11:52 2007
@@ -51,7 +51,7 @@
   alias display show
 
   def client_frame
-    window(tk_call_without_enc('::ttk::dialog::clientframe'))
+    window(tk_call_without_enc('::ttk::dialog::clientframe', @path))
   end
 
   def cget(slot)
