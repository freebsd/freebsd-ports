--- lib/pre_sexp.ml.orig	2015-08-18 11:17:27 UTC
+++ lib/pre_sexp.ml
@@ -32,11 +32,11 @@ let must_escape str =
 let esc_str str =
   let estr = String.escaped str in
   let elen = String.length estr in
-  let res = String.create (elen + 2) in
+  let res = Bytes.create (elen + 2) in
   String.blit estr 0 res 1 elen;
-  res.[0] <- '"';
-  res.[elen + 1] <- '"';
-  res
+  Bytes.set res 0 '"';
+  Bytes.set res (elen + 1) '"';
+  Bytes.unsafe_to_string res
 
 let index_of_newline str start =
   try Some (String.index_from str start '\n')
@@ -898,7 +898,7 @@ let mk_cont_parser cont_parse = (); fun _state str ~ma
     PARSE state str ~max_pos ~pos
 
 MK_PARSER(
-  string, String.length, parse_str, str.[pos],
+  string, String.length, parse_str, String.get str pos,
   state.pstack, state.pstack <- pstack,
   ,,
   Atom pbuf_str, List sexp_lst, [], `Sexp
@@ -906,7 +906,6 @@ MK_PARSER(
 
 let parse = parse_str
 
-
 (* Annot parsers *)
 
 let get_glob_ofs parse_pos pos =
@@ -954,7 +953,7 @@ let mk_annot_list parse_state annot_lst pos =
 let init_annot_pstate () = { Annot.positions = []; stack = [] }
 
 MK_PARSER(
-  string, String.length, parse_str_annot, str.[pos],
+  string, String.length, parse_str_annot, String.get str pos,
   state.pstack.Annot.stack, state.pstack.Annot.stack <- pstack,
   add_annot_pos state pos;,add_annot_pos1 state pos;,
   mk_annot_atom state pbuf_str pos, mk_annot_list state sexp_lst pos,
@@ -995,11 +994,11 @@ let mk_this_parse ?parse_pos my_parse = (); fun ~pos ~
   my_parse ?parse_pos:(Some parse_pos) ?len:(Some len) str
 
 let gen_input_sexp my_parse ?parse_pos ic =
-  let buf = String.create 1 in
+  let buf = Bytes.create 1 in
   let rec loop this_parse =
     let c = input_char ic in
-    buf.[0] <- c;
-    match this_parse ~pos:0 ~len:1 buf with
+    Bytes.set buf 0 c;
+    match this_parse ~pos:0 ~len:1 (Bytes.unsafe_to_string buf) with
     | Done (sexp, _) -> sexp
     | Cont (_, this_parse) -> loop this_parse
   in
@@ -1007,12 +1006,12 @@ let gen_input_sexp my_parse ?parse_pos ic =
 
 let input_sexp ?parse_pos ic = gen_input_sexp parse ?parse_pos ic
 
-let gen_input_rev_sexps my_parse ?parse_pos ?(buf = String.create 8192) ic =
+let gen_input_rev_sexps my_parse ?parse_pos ?(buf = Bytes.create 8192) ic =
   let rev_sexps_ref = ref [] in
-  let buf_len = String.length buf in
+  let buf_len = Bytes.length buf in
   let rec loop this_parse ~pos ~len ~cont_state =
     if len > 0 then
-      match this_parse ~pos ~len buf with
+      match this_parse ~pos ~len (Bytes.unsafe_to_string buf) with
       | Done (sexp, ({ Parse_pos.buf_pos; _ } as parse_pos)) ->
           rev_sexps_ref := sexp :: !rev_sexps_ref;
           let n_parsed = buf_pos - pos in
@@ -1073,9 +1072,9 @@ let of_string str =
   of_string_bigstring "of_string" parse " " String.length String.sub str
 
 let get_bstr_sub_str bstr pos len =
-  let str = String.create len in
-  for i = 0 to len - 1 do str.[i] <- bstr.{pos + i} done;
-  str
+  let str = Bytes.create len in
+  for i = 0 to len - 1 do Bytes.set str i (bstr.{pos + i}) done;
+  Bytes.unsafe_to_string str
 
 let bstr_ws_buf = Array1.create char c_layout 1
 let () = bstr_ws_buf.{0} <- ' '
@@ -1101,8 +1100,8 @@ let load_sexps ?buf file = List.rev (load_rev_sexps ?b
 
 let gen_load_sexp_loc = "Sexplib.Sexp.gen_load_sexp"
 
-let gen_load_sexp my_parse ?(strict = true) ?(buf = String.create 8192) file =
-  let buf_len = String.length buf in
+let gen_load_sexp my_parse ?(strict = true) ?(buf = Bytes.create 8192) file =
+  let buf_len = Bytes.length buf in
   let ic = open_in file in
   let rec loop this_parse ~cont_state =
     let len = input ic buf 0 buf_len in
@@ -1111,10 +1110,10 @@ let gen_load_sexp my_parse ?(strict = true) ?(buf = St
         sprintf "%s: EOF in %s while in state %s"
           gen_load_sexp_loc file (Cont_state.to_string cont_state))
     else
-      match this_parse ~pos:0 ~len buf with
+      match this_parse ~pos:0 ~len (Bytes.unsafe_to_string buf) with
       | Done (sexp, ({ Parse_pos.buf_pos; _ } as parse_pos)) when strict ->
           let rec strict_loop this_parse ~pos ~len =
-            match this_parse ~pos ~len buf with
+            match this_parse ~pos ~len (Bytes.unsafe_to_string buf) with
             | Done _ ->
                 failwith (
                   sprintf "%s: more than one S-expression in file %s"
@@ -1186,7 +1185,7 @@ module Annotated = struct
     Of_sexp_error (Annot.Conv_exn (loc, exc), get_sexp annot_sexp)
 end
 
-let load_sexp_conv ?(strict = true) ?(buf = String.create 8192) file f =
+let load_sexp_conv ?(strict = true) ?(buf = Bytes.create 8192) file f =
   let sexp = load_sexp ~strict ~buf file in
   try `Result (f sexp)
   with Of_sexp_error _ ->
@@ -1200,7 +1199,7 @@ let raise_conv_exn ~file = function
 let load_sexp_conv_exn ?strict ?buf file f =
   raise_conv_exn ~file (load_sexp_conv ?strict ?buf file f)
 
-let load_sexps_conv ?(buf = String.create 8192) file f =
+let load_sexps_conv ?(buf = Bytes.create 8192) file f =
   let rev_sexps = load_rev_sexps ~buf file in
   try List.rev_map (fun sexp -> `Result (f sexp)) rev_sexps
   with Of_sexp_error _ as e ->
@@ -1212,7 +1211,7 @@ let load_sexps_conv ?(buf = String.create 8192) file f
         List.rev_map (fun annot_sexp -> Annotated.conv f annot_sexp)
           rev_annot_sexps
 
-let load_sexps_conv_exn ?(buf = String.create 8192) file f =
+let load_sexps_conv_exn ?(buf = Bytes.create 8192) file f =
   let rev_sexps = load_rev_sexps ~buf file in
   try List.rev_map f rev_sexps
   with Of_sexp_error _ as e ->
