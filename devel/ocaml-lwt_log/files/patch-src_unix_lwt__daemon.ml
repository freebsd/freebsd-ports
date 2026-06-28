--- src/unix/lwt_daemon.ml.orig	2022-08-29 14:58:15 UTC
+++ src/unix/lwt_daemon.ml
@@ -19,15 +19,6 @@
  * 02111-1307, USA.
  *)

-(* [Lwt_sequence] is deprecated – we don't want users outside Lwt using it.
-   However, it is still used internally by Lwt. So, briefly disable warning 3
-   ("deprecated"), and create a local, non-deprecated alias for
-   [Lwt_sequence] that can be referred to by the rest of the code in this
-   module without triggering any more warnings. *)
-[@@@ocaml.warning "-3"]
-module Lwt_sequence = Lwt_sequence
-[@@@ocaml.warning "+3"]
-
 open Lwt.Infix

 let rec copy ic logger =
@@ -61,7 +52,7 @@ let daemonize ?(syslog=true) ?(stdin=`Dev_null) ?(stdo
   (* Exit the parent, and continue in the child: *)
   if Lwt_unix.fork () > 0 then begin
     (* Do not run exit hooks in the parent. *)
-    Lwt_sequence.iter_node_l Lwt_sequence.remove Lwt_main.exit_hooks [@ocaml.warning "-3"];
+    Lwt_main.Exit_hooks.remove_all ();
     exit 0
   end;
