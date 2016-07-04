$NetBSD: patch-at,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/libmojave-external/util/lm_channel.ml.orig	2007-07-16 21:10:43.000000000 +0000
+++ src/libmojave-external/util/lm_channel.ml
@@ -337,12 +337,10 @@ let of_string s =
    of_string string_sym 1 0 (String.copy s)
 
 let info channel =
-   let { channel_id = id;
-         channel_kind = kind;
-         channel_mode = mode;
-         channel_binary = binary
-       } = channel
-   in
+   let id = channel.channel_id in
+   let kind = channel.channel_kind in
+   let mode = channel.channel_mode in
+   let binary = channel.channel_binary in
       id, kind, mode, binary
 
 let name channel =
@@ -468,13 +466,11 @@ let squash_text buffer off amount =
  * Get the line/char for a particular point in the input buffer.
  *)
 let line_of_index info buffer index =
-   let { start_line   = start_line;
-         start_char   = start_char;
-         middle_index = middle_index;
-         middle_line  = middle_line;
-         middle_char  = middle_char
-       } = info
-   in
+   let start_line = info.start_line in
+   let start_char = info.start_char in
+   let middle_index = info.middle_index in
+   let middle_line = info.middle_line in
+   let middle_char = info.middle_char in
    let rec search line char i =
       if i = index then
          begin
@@ -509,12 +505,10 @@ let reset_input_buffer info =
       info.lex_index    <- 0
 
 let shift_input_buffer info =
-   let { in_buffer = in_buffer;
-         in_index  = in_index;
-         lex_index = lex_index;
-         in_max    = in_max
-       } = info
-   in
+   let in_buffer = info.in_buffer in
+   let in_index = info.in_index in
+   let lex_index = info.lex_index in
+   let in_max = info.in_max in
    let line, char = line_of_index info in_buffer in_index in
       String.blit in_buffer in_index in_buffer 0 (in_max - in_index);
       info.start_line   <- line;
@@ -562,10 +556,8 @@ let reset_output_buffer info =
  * flushing.
  *)
 let expand_output info =
-   let { out_buffer = buffer;
-         out_max    = max
-       } = info
-   in
+   let buffer = info.out_buffer in
+   let max = info.out_max in
       if max = String.length buffer then begin
          let buffer2 = String.create (max * 2) in
             String.blit buffer 0 buffer2 0 max;
@@ -575,10 +567,8 @@ let expand_output info =
       end
 
 let to_string info =
-   let { out_buffer = buffer;
-         out_max = max
-       } = info
-   in
+   let buffer = info.out_buffer in
+   let max = info.out_max in
       String.sub buffer 0 max
 
 (************************************************************************
@@ -614,12 +604,10 @@ let setup_write_buffer info =
  *)
 let flush_output_once info =
    setup_write_buffer info;
-   let { write_index  = off;
-         write_max    = max;
-         write_buffer = buf;
-         write_fun    = write
-       } = info
-   in
+   let off = info.write_index in
+   let max = info.write_max in
+   let buf = info.write_buffer in
+   let write = info.write_fun in
    let count = write buf off (max - off) in
    let off' = off + count in
       if off' = max then
@@ -632,17 +620,13 @@ let flush_output_once info =
  *)
 let flush_aux info =
    setup_write_buffer info;
-   let { write_buffer = buf;
-         write_fun    = writer
-       } = info
-   in
+   let buf = info.write_buffer in
+   let writer = info.write_fun in
 
    (* Now write the data directly *)
    let rec write () =
-      let { write_index = index;
-            write_max = max
-          } = info
-      in
+      let index = info.write_index in
+      let max = info.write_max in
       let len = max - index in
          if len <> 0 then
             let count = writer buf index len in
@@ -701,10 +685,8 @@ let close info =
  * Print a byte.
  *)
 let rec output_char info c =
-   let { out_max = max;
-         out_buffer = buffer
-       } = info
-   in
+   let max = info.out_max in
+   let buffer = info.out_buffer in
       flush_input info;
       if max = String.length buffer then
          begin
@@ -724,10 +706,8 @@ let output_byte info c =
  * Write a substring.
  *)
 let rec output_buffer info buf off len =
-   let { out_max = max;
-         out_buffer = buffer
-       } = info
-   in
+   let max = info.out_max in
+   let buffer = info.out_buffer in
    let avail = String.length buffer - max in
       flush_input info;
       if len <> 0 then
@@ -758,21 +738,17 @@ let write info buf off len =
  * Check if there is input already in the buffer.
  *)
 let poll info =
-   let { in_index = index;
-         in_max = max
-       } = info
-   in
+   let index = info.in_index in
+   let max = info.in_max in
       index <> max
 
 (*
  * Get data when the buffer is empty.
  *)
 let fillbuf info =
-   let { channel_binary = binary;
-         in_buffer = buf;
-         read_fun = reader
-       } = info
-   in
+   let binary = info.channel_binary in
+   let buf = info.in_buffer in
+   let reader = info.read_fun in
    let count = reader buf 0 buf_size in
    let count =
       if count = 0 then
@@ -797,11 +773,9 @@ let fillbuf info =
  * Get a single char.
  *)
 let rec input_char info =
-   let { in_index = index;
-         in_max = max;
-         in_buffer = buf;
-       } = info
-   in
+   let index = info.in_index in
+   let max = info.in_max in
+   let buf = info.in_buffer in
       flush_output info;
       if index = max then
          begin
@@ -823,11 +797,9 @@ let input_byte info =
  * Read data into a buffer.
  *)
 let rec input_buffer info s off len =
-   let { in_index = index;
-         in_max = max;
-         in_buffer = buf
-       } = info
-   in
+   let index = info.in_index in
+   let max = info.in_max in
+   let buf = info.in_buffer in
    let avail = max - index in
       flush_output info;
       if len <> 0 then
@@ -884,12 +856,10 @@ let input_entire_line info =
  * Read allows for partial reading.
  *)
 let read info s off len =
-   let { in_index = index;
-         in_max = max;
-         in_buffer = buf;
-         read_fun = reader
-       } = info
-   in
+   let index = info.in_index in
+   let max = info.in_max in
+   let buf = info.in_buffer in
+   let reader = info.read_fun in
    let avail = max - index in
       flush_output info;
       if avail = 0 then
@@ -925,13 +895,11 @@ let seek info pos whence =
  * Get the current location.
  *)
 let loc info =
-   let { out_max = out_max;
-         in_index = in_index;
-         in_buffer = in_buffer;
-         out_buffer = out_buffer;
-         channel_file = file
-       } = info
-   in
+   let out_max = info.out_max in
+   let in_index = info.in_index in
+   let in_buffer = info.in_buffer in
+   let out_buffer = info.out_buffer in
+   let file = info.channel_file in
    let line, char =
       if out_max <> 0 then
          line_of_index info out_buffer out_max
@@ -1132,10 +1100,8 @@ struct
     * Start lex mode.
     *)
    let lex_start channel =
-      let { in_index = index;
-            in_buffer = buffer
-          } = channel
-      in
+      let index = channel.in_index in
+      let buffer = channel.in_buffer in
       let prev =
          if index = 0 then
             bof
@@ -1149,10 +1115,8 @@ struct
     * Restart at a previous position.
     *)
    let lex_restart channel pos =
-      let { in_max = max;
-            in_index = index
-          } = channel
-      in
+      let max = channel.in_max in
+      let index = channel.in_index in
          assert (pos >= 0 && pos <= max - index);
          channel.lex_index <- index + pos
 
@@ -1168,20 +1132,16 @@ struct
     * Get the string matched by the lexer.
     *)
    let lex_string channel pos =
-      let { in_index = start;
-            in_buffer = buffer
-          } = channel
-      in
+      let start = channel.in_index in
+      let buffer = channel.in_buffer in
          String.sub buffer start pos
 
    (*
     * Get the string matched by the lexer.
     *)
    let lex_substring channel off len =
-      let { in_index = start;
-            in_buffer = buffer
-          } = channel
-      in
+      let start = channel.in_index in
+      let buffer = channel.in_buffer in
          String.sub buffer (start + off) len
 
    (*
@@ -1189,13 +1149,11 @@ struct
     * We can't discard any of the existing data.
     *)
    let rec lex_fill channel =
-      let { in_max         = max;
-            in_buffer      = buffer;
-            in_index       = start;
-            read_fun       = reader;
-            channel_binary = binary
-          } = channel
-      in
+      let max = channel.in_max in
+      let buffer = channel.in_buffer in
+      let start = channel.in_index in
+      let reader = channel.read_fun in
+      let binary = channel.channel_binary in
       let len = String.length buffer in
       let amount = len - max in
          (* If we have space, fill it *)
@@ -1245,11 +1203,9 @@ struct
     * Get the next character in lex mode.
     *)
    let lex_next channel =
-      let { in_max = max;
-            in_buffer = buffer;
-            lex_index = index
-          } = channel
-      in
+      let max = channel.in_max in
+      let buffer = channel.in_buffer in
+      let index = channel.lex_index in
          if index = max then
             lex_fill channel
          else
@@ -1267,14 +1223,12 @@ struct
     * Get the location of the buffer.
     *)
    let lex_loc channel off =
-      let { start_line = line;
-            start_char = char;
-            channel_file = file;
-            lex_index = index;
-            in_buffer = buffer;
-            in_max = max
-          } = channel
-      in
+      let line = channel.start_line in
+      let char = channel.start_char in
+      let file = channel.channel_file in
+      let index = channel.lex_index in
+      let buffer = channel.in_buffer in
+      let max = channel.in_max in
       let line1, char1 =
          if index > max then
             line, char
@@ -1293,11 +1247,9 @@ struct
     * Add any remaining buffered text to a buffer.
     *)
    let lex_buffer channel buf =
-      let { in_max    = max;
-            in_buffer = buffer;
-            in_index  = start
-          } = channel
-      in
+      let max = channel.in_max in
+      let buffer = channel.in_buffer in
+      let start = channel.in_index in
          Buffer.add_substring buf buffer start (max - start);
          channel.in_index <- max
 end
