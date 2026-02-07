--- strExtras.mli.orig	2006-02-23 06:34:35 UTC
+++ strExtras.mli
@@ -105,10 +105,10 @@ type trim_style = [ `Both | `Left | `Right ]
 val trim: ?style:trim_style -> string -> char -> string
 
 (** Like [map], but modifies the argument string. *)
-val map_inplace: (char -> char) -> string -> unit
+val map_inplace: (char -> char) -> bytes -> unit
 
 (** Like [map_inplace], but passes the index of the character as well. *)
-val mapi_inplace: (char -> int -> char) -> string -> unit
+val mapi_inplace: (char -> int -> char) -> bytes -> unit
 
 (** Returns a reversed version of the string *)
 val rev: string -> string
