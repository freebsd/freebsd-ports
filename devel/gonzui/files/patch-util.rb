--- gonzui/util.rb~	Mon Nov 29 08:29:48 2004
+++ gonzui/util.rb	Wed Dec  1 17:29:47 2004
@@ -223,7 +223,7 @@
 
   module UTF8
     # FIXME: should be customizable.
-    Preference = ["iso-2022-jp", "euc-jp", "utf-8", "shift_jis", "windows-31j"]
+    Preference = ["iso-2022-jp", "euc-jp", "utf-8", "shift_jis"]
 
     module_function
     def to_utf8 (str)
