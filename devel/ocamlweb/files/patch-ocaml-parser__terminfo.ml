--- ocaml-parser/terminfo.ml--	Mon Aug 16 21:38:18 2004
+++ ocaml-parser/terminfo.ml	Mon Aug 16 21:38:30 2004
@@ -19,7 +19,7 @@
   | Bad_term
   | Good_term of int
 ;;
-external setup : out_channel -> status = "terminfo_setup";;
-external backup : int -> unit = "terminfo_backup";;
-external standout : bool -> unit = "terminfo_standout";;
-external resume : int -> unit = "terminfo_resume";;
+external setup : out_channel -> status = "caml_terminfo_setup";;
+external backup : int -> unit = "caml_terminfo_backup";;
+external standout : bool -> unit = "caml_terminfo_standout";;
+external resume : int -> unit = "caml_terminfo_resume";;
