--- share/pkgs/gui-lib/mred/private/wx/gtk/queue.rkt.orig	2016-04-22 21:19:48 UTC
+++ share/pkgs/gui-lib/mred/private/wx/gtk/queue.rkt
@@ -9,7 +9,6 @@
          "clipboard.rkt"
          "const.rkt"
 	 "w32.rkt"
-         "unique.rkt"
          "../common/keep-forever.rkt")
 
 (provide (protect-out gtk-start-event-pump
@@ -83,8 +82,6 @@
           (error (format
                   "Gtk initialization failed for display ~s"
                   (or display ":0"))))
-        (when single-instance?
-          (do-single-instance))
         (let ([v (scheme_register_process_global "Racket-GUI-wm-class" #f)])
           (when v
             (gdk_set_program_class (cast v _pointer _string))))
