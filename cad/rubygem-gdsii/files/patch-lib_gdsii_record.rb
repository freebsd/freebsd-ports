--- lib/gdsii/record.rb.orig	2016-05-16 07:41:38 UTC
+++ lib/gdsii/record.rb
@@ -102,13 +102,13 @@ module Gdsii
         
         # convert to a data type object
         @data = case RECORD_INFO[type].data_type
-                when GDT_ASCII    : Ascii.new(data, self)
-                when GDT_INT2     : Int2.new(data)
-                when GDT_INT4     : Int4.new(data)
-                when GDT_REAL8    : Real8.new(data)
-                when GDT_BITARRAY : BitArray.new(data)
-                when GDT_NO_DATA  : NoData.new()
-                when GDT_REAL4    : Real4.new(data)
+                when GDT_ASCII     then Ascii.new(data, self)
+                when GDT_INT2      then Int2.new(data)
+                when GDT_INT4      then Int4.new(data)
+                when GDT_REAL8     then Real8.new(data)
+                when GDT_BITARRAY  then BitArray.new(data)
+                when GDT_NO_DATA   then NoData.new()
+                when GDT_REAL4     then Real4.new(data)
                 else
                   raise TypeError, "Given record type (#{type}) is invalid"
                 end
@@ -246,13 +246,13 @@ module Gdsii
         end
                 
         data = case data_type
-               when GDT_ASCII    : Ascii.read(file, bytes_left)
-               when GDT_INT2     : Int2.read(file, bytes_left)
-               when GDT_INT4     : Int4.read(file, bytes_left)
-               when GDT_REAL8    : Real8.read(file, bytes_left)
-               when GDT_BITARRAY : BitArray.read(file, bytes_left)
-               when GDT_NO_DATA  : NoData.read(file, bytes_left)
-               when GDT_REAL4    : Real4.read(file, bytes_left)
+               when GDT_ASCII     then Ascii.read(file, bytes_left)
+               when GDT_INT2      then Int2.read(file, bytes_left)
+               when GDT_INT4      then Int4.read(file, bytes_left)
+               when GDT_REAL8     then Real8.read(file, bytes_left)
+               when GDT_BITARRAY  then BitArray.read(file, bytes_left)
+               when GDT_NO_DATA   then NoData.read(file, bytes_left)
+               when GDT_REAL4     then Real4.read(file, bytes_left)
                else
                  raise TypeError, "Given record type (#{type}) is invalid"
                end
