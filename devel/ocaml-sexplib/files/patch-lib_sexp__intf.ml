--- lib/sexp_intf.ml.orig	2015-08-18 11:17:27 UTC
+++ lib/sexp_intf.ml
@@ -192,12 +192,12 @@ module type S = sig
         annotated S-expression instead. *)
 
     val input_sexps :
-      ?parse_pos : Parse_pos.t -> ?buf : string -> in_channel -> t list
+      ?parse_pos : Parse_pos.t -> ?buf : bytes -> in_channel -> t list
     (** [input_sexps ?parse_pos ?buf ic] like {!input_sexps}, but returns
         a list of annotated S-expressions. *)
 
     val input_rev_sexps :
-      ?parse_pos : Parse_pos.t -> ?buf : string -> in_channel -> t list
+      ?parse_pos : Parse_pos.t -> ?buf : bytes -> in_channel -> t list
     (** [input_sexps ?parse_pos ?buf ic] like {!input_rev_sexps}, but
         returns a list of annotated S-expressions. *)
 
@@ -207,15 +207,15 @@ module type S = sig
     (** NOTE: these functions should only be used if an annotated S-expression
         is required. *)
 
-    val load_sexp : ?strict : bool -> ?buf : string -> string -> t
+    val load_sexp : ?strict : bool -> ?buf : bytes -> string -> t
     (** [load_sexp ?strict ?buf file] like {!load_sexp}, but returns an
         annotated S-expression. *)
 
-    val load_sexps : ?buf : string -> string -> t list
+    val load_sexps : ?buf : bytes -> string -> t list
     (** [load_sexps ?buf file] like {!load_sexps}, but returns a list of
         annotated S-expressions. *)
 
-    val load_rev_sexps : ?buf : string -> string -> t list
+    val load_rev_sexps : ?buf : bytes -> string -> t list
     (** [load_rev_sexps ?buf file] like {!load_rev_sexps}, but returns a
         list of annotated S-expressions. *)
 
@@ -311,7 +311,7 @@ module type S = sig
   *)
 
   val input_sexps :
-    ?parse_pos : Parse_pos.t -> ?buf : string -> in_channel -> t list
+    ?parse_pos : Parse_pos.t -> ?buf : bytes -> in_channel -> t list
   (** [input_sexps ?parse_pos ?buf ic] parses whitespace separated
       S-expressions from input channel [ic] until EOF is reached.  Faster than
       the scan-functions.
@@ -320,7 +320,7 @@ module type S = sig
   *)
 
   val input_rev_sexps :
-    ?parse_pos : Parse_pos.t -> ?buf : string -> in_channel -> t list
+    ?parse_pos : Parse_pos.t -> ?buf : bytes -> in_channel -> t list
   (** [input_rev_sexps ?parse_pos ?buf ic] same as {!Sexp.input_sexps},
       but returns a reversed list of S-expressions, which is slightly more
       efficient. *)
@@ -328,7 +328,7 @@ module type S = sig
 
   (** {6 Loading of (converted) S-expressions} *)
 
-  val load_sexp : ?strict : bool -> ?buf : string -> string -> t
+  val load_sexp : ?strict : bool -> ?buf : bytes -> string -> t
   (** [load_sexp ?strict ?buf file] reads one S-expression from [file] using
       buffer [buf] for storing intermediate data.  Faster than the
       scan-functions.
@@ -344,7 +344,7 @@ module type S = sig
       @param strict default = [true]
   *)
 
-  val load_sexps : ?buf : string -> string -> t list
+  val load_sexps : ?buf : bytes -> string -> t list
   (** [load_sexps ?buf file] reads a list of whitespace separated S-expressions
       from [file] using buffer [buf] for storing intermediate data.
       Faster than the scan-functions.
@@ -355,12 +355,12 @@ module type S = sig
       S-expression could be fully read.
   *)
 
-  val load_rev_sexps : ?buf : string -> string -> t list
+  val load_rev_sexps : ?buf : bytes -> string -> t list
   (** [load_rev_sexps ?buf file] same as {!Sexp.load_sexps}, but returns a
       reversed list of S-expressions, which is slightly more efficient. *)
 
   val load_sexp_conv :
-    ?strict : bool -> ?buf : string -> string -> (t -> 'a) -> 'a Annotated.conv
+    ?strict : bool -> ?buf : bytes -> string -> (t -> 'a) -> 'a Annotated.conv
   (** [load_sexp_conv ?strict ?buf file f] like {!Sexp.load_sexp}, but
       performs a conversion on the fly using [f].  Performance is equivalent
       to executing {!Sexp.load_sexp} and performing conversion when there
@@ -375,13 +375,13 @@ module type S = sig
   *)
 
   val load_sexp_conv_exn :
-    ?strict : bool -> ?buf : string -> string -> (t -> 'a) -> 'a
+    ?strict : bool -> ?buf : bytes -> string -> (t -> 'a) -> 'a
   (** [load_sexp_conv_exn ?strict ?buf file f] like {!load_sexp_conv},
       but returns the converted value or raises [Of_sexp_error] with exact
       location information in the case of a conversion error. *)
 
   val load_sexps_conv :
-    ?buf : string -> string -> (t -> 'a) -> 'a Annotated.conv list
+    ?buf : bytes -> string -> (t -> 'a) -> 'a Annotated.conv list
   (** [load_sexps_conv ?buf file f] like {!Sexp.load_sexps}, but performs
       a conversion on the fly using [f].  Performance is equivalent to
       executing {!Sexp.load_sexps} and performing conversion when there
@@ -395,7 +395,7 @@ module type S = sig
       S-expression could be fully read.
   *)
 
-  val load_sexps_conv_exn : ?buf : string -> string -> (t -> 'a) -> 'a list
+  val load_sexps_conv_exn : ?buf : bytes -> string -> (t -> 'a) -> 'a list
   (** [load_sexps_conv_exn ?buf file f] like {!load_sexps_conv}, but returns
       the converted value or raises [Of_sexp_error] with exact location
       information in the case of a conversion error. *)
@@ -611,14 +611,16 @@ module type S = sig
     type pos = Src_pos.Relative.t = { row : int; col : int }
     val sexp_of_pos : pos -> Type.t
 
-    (** S-expressions annotated with relative source positions and comments *)
-    type t =
+    (** S-expressions annotated with relative source positions and comments. All the
+        positions are relative to the opening paren of the enclosing list, or the first
+        character of the file. *)
+    type t = Type_with_layout.t =
       | Atom of pos * string * string option (* second is quoted representation *)
       | List of pos * t_or_comment list * pos (* positions of left and right parens *)
-    and t_or_comment =
+    and t_or_comment = Type_with_layout.t_or_comment =
       | Sexp of t
       | Comment of comment
-    and comment =
+    and comment = Type_with_layout.comment =
       | Plain_comment of pos * string (* line or block comment *)
       | Sexp_comment of pos * comment list * t (* position of #; *)
 
