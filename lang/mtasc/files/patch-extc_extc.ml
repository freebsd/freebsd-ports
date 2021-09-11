--- extc/extc.ml.orig	2007-02-26 13:00:51 UTC
+++ extc/extc.ml
@@ -34,11 +34,11 @@ type zresult = {
 }
 
 external zlib_deflate_init : int -> zstream = "zlib_deflate_init"
-external zlib_deflate : zstream -> src:string -> spos:int -> slen:int -> dst:string -> dpos:int -> dlen:int -> zflush -> zresult = "zlib_deflate_bytecode" "zlib_deflate"
+external zlib_deflate : zstream -> src:string -> spos:int -> slen:int -> dst:bytes -> dpos:int -> dlen:int -> zflush -> zresult = "zlib_deflate_bytecode" "zlib_deflate"
 external zlib_deflate_end : zstream -> unit = "zlib_deflate_end"
 
 external zlib_inflate_init : unit -> zstream = "zlib_inflate_init"
-external zlib_inflate : zstream -> src:string -> spos:int -> slen:int -> dst:string -> dpos:int -> dlen:int -> zflush -> zresult = "zlib_inflate_bytecode" "zlib_inflate"
+external zlib_inflate : zstream -> src:string -> spos:int -> slen:int -> dst:bytes -> dpos:int -> dlen:int -> zflush -> zresult = "zlib_inflate_bytecode" "zlib_inflate"
 external zlib_inflate_end : zstream -> unit = "zlib_inflate_end"
 
 external _executable_path : string -> string = "executable_path"
@@ -60,7 +60,7 @@ let zlib_op op z str =
 	let rec loop pos len acc =
 		let r = op z ~src:str ~spos:pos ~slen:len ~dst:tmp ~dpos:0 ~dlen:bufsize (if len = 0 then Z_FINISH else Z_SYNC_FLUSH) in
 		total := !total + r.z_wrote;
-		let acc = String.sub tmp 0 r.z_wrote :: acc in
+		let acc = Bytes.sub_string tmp 0 r.z_wrote :: acc in
 		if r.z_finish then
 			acc
 		else
@@ -74,7 +74,7 @@ let zlib_op op z str =
 		String.unsafe_blit s 0 big p l;
 		p
 	) !total strings);
-	big
+	Bytes.unsafe_to_string big
 
 let zip str =
 	let z = zlib_deflate_init 9 in
