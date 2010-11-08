--- automate.ml.orig	2010-11-05 11:14:53.000000000 +0100
+++ automate.ml	2010-11-05 11:14:55.000000000 +0100
@@ -44,7 +44,7 @@ type output = [
   | `OUTPUT       of string
   | `ERROR        of string
   | `SYNTAX_ERROR of string]
-type chunk = command_id * int * bool * string
+type chunk = command_id * bool * string
 type process = {
     p_in  :  in_watch ;
     p_out : out_watch ;
@@ -152,7 +152,7 @@ let _read_cb w conditions =
     try 
       match Giochannel.read_chars w.out_w.w_chan w.out_sb with
       | `NORMAL read ->
-	  if debug then log "%s cb: read %d" w.out_w.w_name read ;
+	  if debug then log "%s cb: read %d" w.out_w.w_name read;
 	  Buffer.add_substring w.out_buffer w.out_sb 0 read ;
 	  w.out_cb w.out_buffer
       | `EOF ->
@@ -258,8 +258,8 @@ let encode_stdio cmd =
 
 
 
-let find_four_colon b =
-  let to_find = ref 4 in
+let find_three_colon b =
+  let to_find = ref 3 in
   let i = ref 0 in
   while !to_find > 0 do
     let c = Buffer.nth b !i in
@@ -277,22 +277,20 @@ let truncate_buffer b off len =
 
 let decode_stdio_chunk b =
   try
-    let header_len = find_four_colon b in
+    let header_len = find_three_colon b in
     let h = Buffer.sub b 0 header_len in
     let c1 = String.index_from h 0 ':' in
     let number = int_of_string (string_slice ~e:c1 h) in
-    let code   = int_of_char h.[c1 + 1] - int_of_char '0' in
     let c2 = String.index_from h (c1 + 1) ':' in
-    let last   = h.[c2 + 1] in
+    let last   = h.[c1 + 1] in
     let c3 = String.index_from h (c2 + 1) ':' in
-    let c4 = String.index_from h (c3 + 1) ':' in
-    let len   = int_of_string (string_slice ~s:(c3 + 1) ~e:c4 h) in
+    let len   = int_of_string (string_slice ~s:(c2 + 1) ~e:c3 h) in
     if Buffer.length b < header_len + len
     then
       `INCOMPLETE
     else
       let data = truncate_buffer b header_len len in
-      `CHUNK (number, code, last = 'l', data)
+      `CHUNK (number, last = 'l', data)
   with Invalid_argument _ ->
     `INCOMPLETE
 
@@ -305,11 +303,11 @@ let rec out_cb p b =
   | `INCOMPLETE ->
       ()
 
-  | `CHUNK (nb, _, _, _) when aborted_cmd p nb ->
+  | `CHUNK (nb, _, _) when aborted_cmd p nb ->
       p.chunks <- List.remove_assoc nb p.chunks ;
       out_cb p b
 
-  | `CHUNK ((nb, code, false, data) as chunk) ->
+  | `CHUNK ((nb, false, data) as chunk) ->
       if debug then log "decoded a chunk" ;
       let previous_chunks =
 	try List.assoc nb p.chunks
@@ -320,7 +318,7 @@ let rec out_cb p b =
       previous_chunks := chunk :: !previous_chunks ;
       out_cb p b
 
-  | `CHUNK ((nb, code, true, data) as chunk) ->
+  | `CHUNK ((nb, true, data) as chunk) ->
       if debug then log "decoded last chunk" ;
       let chunks =
 	try 
@@ -333,14 +331,14 @@ let rec out_cb p b =
       p.callbacks <- List.remove_assoc nb p.callbacks ;
       let msg = 
 	String.concat ""
-	  (List.map (fun (_, _, _, d) -> d) chunks) in
-      let data =
-	match code with
-	| 0 -> `OUTPUT msg
-	| 1 -> `SYNTAX_ERROR msg
-	| 2 -> `ERROR msg
+	  (List.map (function (_, false, d) -> d | (_, true, d) -> "") chunks) in
+      let code =
+	match data with
+	| "0" -> `OUTPUT msg
+	| "1" -> `SYNTAX_ERROR msg
+	| "2" -> `ERROR msg
 	| _ -> failwith "invalid_code in automate stdio output" in
-      ignore (Glib.Idle.add ~prio:0 (fun () -> cb data ; false)) ;
+      ignore (Glib.Idle.add ~prio:0 (fun () -> cb code ; false)) ;
       out_cb p b
 
 
@@ -409,6 +407,20 @@ let spawn mtn db = 
       chunks = [] ;
       exit_cb = (fun _ -> assert false)
     } in
+  let rec check_version buf =
+    if String.contains buf '\n' then
+      String.length buf >= 18 && String.sub buf 0 18 = "format-version: 2\n"
+    else
+      match Giochannel.read_chars p.p_out.out_w.w_chan p.p_out.out_sb  with
+      | `NORMAL read -> check_version (buf ^ String.sub p.p_out.out_sb 0 read)
+      | `EOF ->
+	  Giochannel.shutdown p.p_out.out_w.w_chan false;
+	  Giochannel.shutdown p.p_err.out_w.w_chan false;
+	  failwith "mtn version 0.46 or above is required";
+      | `AGAIN -> check_version buf
+  in
+  if not (check_version "")
+  then failwith "mtn stdio uses an unknown format-version";
   let pid = some child.Gspawn.pid in
   ignore (Gspawn.add_child_watch ~prio:50 pid (reap_cb p pid)) ;
   p.p_out.out_cb <- out_cb p ;
