--- pGOCaml.mli.orig	2009-03-01 09:59:09.188523102 -0500
+++ pGOCaml.mli	2009-03-01 09:59:43.562605632 -0500
@@ -20,6 +20,8 @@
  * Boston, MA 02111-1307, USA.
  *)
 
+open CalendarLib
+
 type 'a t				(** Database handle. *)
 
 exception Error of string
