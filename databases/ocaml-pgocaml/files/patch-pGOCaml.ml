--- pGOCaml.ml.orig	2009-03-01 09:59:13.864728737 -0500
+++ pGOCaml.ml	2009-03-01 09:59:53.353002107 -0500
@@ -22,6 +22,7 @@
 
 open Printf
 open ExtString
+open CalendarLib
 
 type 'a t = {
   ichan : in_channel;			(* In_channel wrapping socket. *)
