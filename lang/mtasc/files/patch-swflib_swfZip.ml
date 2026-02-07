--- swflib/swfZip.ml.orig	2004-11-03 02:38:17 UTC
+++ swflib/swfZip.ml
@@ -24,13 +24,13 @@ let deflate o =
 	let buf = Buffer.create 0 in
 	let flush() =
 		let data = Buffer.contents buf in
-		IO.nwrite o (Extc.zip data);
+		IO.nwrite_string o (Extc.zip data);
 		IO.flush o;
 		Buffer.reset buf;
 	in
 	IO.create_out 
 		~write:(Buffer.add_char buf)
-		~output:(fun s p l -> Buffer.add_substring buf s p l; l)
+		~output:(fun s p l -> Buffer.add_subbytes buf s p l; l)
 		~flush
 		~close:(fun () -> flush(); IO.close_out o)
 
