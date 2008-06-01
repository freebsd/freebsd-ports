--- lablgtk/src/gContainer.mli.orig	2008-05-01 20:41:05.000000000 +0200
+++ lablgtk/src/gContainer.mli	2008-05-01 20:41:09.000000000 +0200
@@ -20,7 +20,7 @@
 (*                                                                        *)
 (**************************************************************************)
 
-(* $Id: gContainer.mli 1347 2007-06-20 07:40:34Z guesdon $ *)
+(* $Id: gContainer.mli 1397 2008-02-26 00:21:39Z garrigue $ *)
 
 open Gtk
 open GObj
@@ -92,11 +92,12 @@ val cast_container : widget -> container
 
 (** @gtkdoc gtk GtkContainer *)
 val pack_container :
-  create:([> Gtk.container] Gobject.param list -> (#GObj.widget as 'a)) ->
-  [> Gtk.container] Gobject.param list ->
+  create:(([> Gtk.container] as 'a) Gobject.param list ->
+          (#GObj.widget as 'b)) ->
+  'a Gobject.param list ->
   ?border_width:int ->
   ?width:int ->
-  ?height:int -> ?packing:(GObj.widget -> unit) -> ?show:bool -> unit -> 'a
+  ?height:int -> ?packing:(GObj.widget -> unit) -> ?show:bool -> unit -> 'b
 
 (** {3 GtkBin} *)
 
