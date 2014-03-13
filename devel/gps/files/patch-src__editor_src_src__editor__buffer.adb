--- src_editor/src/src_editor_buffer.adb.orig	2012-09-28 15:42:43.000000000 +0000
+++ src_editor/src/src_editor_buffer.adb
@@ -5820,7 +5820,7 @@ package body Src_Editor_Buffer is
 
          while Result
            and then not Ends_Line (Iter)
-           and then Is_Space (Get_Char (Iter))
+           and then Glib.Unicode.Is_Space (Gtk.Text_Iter.Get_Char (Iter))
          loop
             Forward_Char (Iter, Result);
             Offset := Offset + 1;
