--- lib/gdsii/element.rb.orig	2016-05-16 07:41:38 UTC
+++ lib/gdsii/element.rb
@@ -56,13 +56,13 @@ module Gdsii
     def Element.read(file, *args)
       rec = Record.peek(file)
       case rec.type
-      when GRT_BOUNDARY : Boundary.read_el(file, *args)
-      when GRT_TEXT     : Text.read_el(file, *args)
-      when GRT_PATH     : Path.read_el(file, *args)
-      when GRT_SREF     : SRef.read_el(file, *args)
-      when GRT_AREF     : ARef.read_el(file, *args)
-      when GRT_BOX      : Box.read_el(file, *args)
-      when GRT_NODE     : Node.read_el(file, *args)
+      when GRT_BOUNDARY  then Boundary.read_el(file, *args)
+      when GRT_TEXT      then Text.read_el(file, *args)
+      when GRT_PATH      then Path.read_el(file, *args)
+      when GRT_SREF      then SRef.read_el(file, *args)
+      when GRT_AREF      then ARef.read_el(file, *args)
+      when GRT_BOX       then Box.read_el(file, *args)
+      when GRT_NODE      then Node.read_el(file, *args)
       else
         # end of the element, increment the counter and move on
         nil
