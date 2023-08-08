--- Camomile/public/charEncoding.mli.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/charEncoding.mli
@@ -130,12 +130,12 @@ module type Interface = sig
       {!OOChannel.obj_output_channel} which
       receives Unicode characters and outputs them to [outchan] using
       the encoding [enc]. *)
-  class out_channel : t -> Pervasives.out_channel -> [UChar.t] obj_output_channel
+  class out_channel : t -> Stdlib.out_channel -> [UChar.t] obj_output_channel
 
   (** [new in_channel enc inchan] creates the intput channel object 
       {!OOChannel.obj_input_channel} which
       reads bytes from [inchan] and converts them to Unicode characters. *)
-  class in_channel : t -> Pervasives.in_channel -> [UChar.t] obj_input_channel
+  class in_channel : t -> Stdlib.in_channel -> [UChar.t] obj_input_channel
 
   (** [ustream_of enc chars] converts the byte stream [chars] 
       to the Unicode character stream by the encoding [enc]. *)
