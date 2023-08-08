--- Camomile/public/oOChannel.mli.orig	2019-08-08 07:10:33 UTC
+++ Camomile/public/oOChannel.mli
@@ -113,7 +113,7 @@ class char_obj_output_channel_of : char_output_channel
   [char] obj_output_channel
 
 (** Convert an OCaml input channel to an OO-based character input channel *)
-class of_in_channel : Pervasives.in_channel -> char_input_channel
+class of_in_channel : Stdlib.in_channel -> char_input_channel
 
 (** Convert an OCaml output channel to an OO-based character output channel *)
-class of_out_channel : Pervasives.out_channel -> char_output_channel
+class of_out_channel : Stdlib.out_channel -> char_output_channel
