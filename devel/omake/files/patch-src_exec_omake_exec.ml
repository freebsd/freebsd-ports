--- src/exec/omake_exec.ml.orig	2009-04-11 14:50:31.000000000 +0400
+++ src/exec/omake_exec.ml	2009-04-11 14:50:36.000000000 +0400
@@ -46,8 +46,6 @@
 open Omake_options
 open Omake_command_type
 
-external sync : unit -> unit = "caml_sync"
-
 module Exec =
 struct
    (*
