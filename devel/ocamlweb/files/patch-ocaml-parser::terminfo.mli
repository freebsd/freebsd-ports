--- ocaml-parser/terminfo.mli--	Mon Aug 16 21:37:42 2004
+++ ocaml-parser/terminfo.mli	Mon Aug 16 21:37:56 2004
@@ -19,7 +19,7 @@
   | Bad_term
   | Good_term of int  (* number of lines of the terminal *)
 ;;
-external setup : out_channel -> status = "terminfo_setup";;
-external backup : int -> unit = "terminfo_backup";;
-external standout : bool -> unit = "terminfo_standout";;
-external resume : int -> unit = "terminfo_resume";;
+external setup : out_channel -> status = "caml_terminfo_setup";;
+external backup : int -> unit = "caml_terminfo_backup";;
+external standout : bool -> unit = "caml_terminfo_standout";;
+external resume : int -> unit = "caml_terminfo_resume";;
