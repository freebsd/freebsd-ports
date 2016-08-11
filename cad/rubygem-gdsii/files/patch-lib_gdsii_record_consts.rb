--- lib/gdsii/record/consts.rb.orig	2016-05-16 07:41:38 UTC
+++ lib/gdsii/record/consts.rb
@@ -55,8 +55,8 @@ module Gdsii
     # Returns the minimum number of items necessary for this record type.
     def min_items
       case @data_type
-      when GDT_NO_DATA : 0
-      when GDT_ASCII   : (@size == 0) ? 1 : @min_len/@size
+      when GDT_NO_DATA  then 0
+      when GDT_ASCII    then (@size == 0) ? 1 : @min_len/@size
       else 
         @min_len/@size
       end
@@ -65,8 +65,8 @@ module Gdsii
     # Returns the maximum number of items necessary for this record type.
     def max_items
       case @data_type
-      when GDT_NO_DATA : 0
-      when GDT_ASCII   : (@size == 0) ? 1 : @max_len/@size
+      when GDT_NO_DATA  then 0
+      when GDT_ASCII    then (@size == 0) ? 1 : @max_len/@size
       else 
         @max_len/@size
       end
