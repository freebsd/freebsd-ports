--- lib/lexer.mll.orig	2015-08-18 11:17:27 UTC
+++ lib/lexer.mll
@@ -54,7 +54,7 @@
       type t
       val create : int -> t
       val add_char : t -> char -> unit
-      val add_substring : t -> string -> int -> int -> unit
+      val add_subbytes : t -> bytes -> int -> int -> unit
       val add_lexeme : t -> lexbuf -> unit
       val clear : t -> unit
       val of_buffer : Buffer.t -> t
@@ -189,7 +189,7 @@ and scan_string buf start = parse
       {
         let ofs = lexbuf.lex_start_pos in
         let len = lexbuf.lex_curr_pos - ofs in
-        Quoted_string_buffer.add_substring buf lexbuf.lex_buffer ofs len;
+        Quoted_string_buffer.add_subbytes buf lexbuf.lex_buffer ofs len;
         Quoted_string_buffer.add_lexeme buf lexbuf;
         scan_string buf start lexbuf
       }
@@ -294,7 +294,7 @@ and scan_block_comment buf locs = parse
         let create n = {contents = Buffer.create n; lexeme = Buffer.create n}
         let of_buffer contents = { contents; lexeme = Buffer.create 64 }
         let add_char t ch = Buffer.add_char t.contents ch
-        let add_substring t str ofs len = Buffer.add_substring t.contents str ofs len
+        let add_subbytes t str ofs len = Buffer.add_subbytes t.contents str ofs len
         let add_lexeme t lexbuf = Buffer.add_string t.lexeme (Lexing.lexeme lexbuf)
         let clear t = Buffer.clear t.lexeme; Buffer.clear t.contents
       end
