--- options.ml
+++ options.ml
@@ -93,7 +93,7 @@ end
 (*********************************************************************)
 (* 'a is the data type, 'b is the widget type *)
 
-class virtual ['a,'b] option ?name ~text ~set:(set:'a->unit) ~get () =
+class virtual ['a,'b,'c] option ?name ~text ~set:(set:'a->unit) ~get () =
   let name = (match name with
 		  None -> random_name 10
 		| Some name -> name ) in
@@ -104,7 +104,7 @@ object (self)
   val name = name
   val text = (text : string)
 
-  method virtual build_widget : live:bool -> 'b 
+  method virtual build_widget : live:bool -> 'b
   method display ~live parent =
     ignore (self#build_widget ~live parent);
     match widget with 
@@ -126,9 +126,9 @@ end
 
 (*********************)
 
-class ['b] toggle_option ?name ~text ~set ~get () =
+class ['b,'c] toggle_option ?name ~text ~set ~get () =
 object (self)
-  inherit [bool,'b] option ?name ~text ~set ~get ()
+  inherit [bool,'b,'c] option ?name ~text ~set ~get ()
     
   method set_tk bool = 
     Textvariable.set tk_var (if bool then "true" else "false")
@@ -153,9 +153,9 @@ end
 
 (*********************)
 
-class ['b] int_scale_option ?name ~min ~max ~text ~set ~get () =
+class ['b,'c] int_scale_option ?name ~min ~max ~text ~set ~get () =
 object (self)
-  inherit [int,'b] option ?name ~text ~set ~get ()
+  inherit [int,'b,'c] option ?name ~text ~set ~get ()
   val min = min
   val max = max
 
@@ -192,10 +192,10 @@ end
 
 (*******************************************************)
 
-class ['b] float_scale_option ?name ~min ~max ?(resolution=1.0) 
+class ['b, 'c] float_scale_option ?name ~min ~max ?(resolution=1.0)
   ~text ~set ~get () = 
 object (self)
-  inherit [float, 'b] option ?name ~text ~set ~get ()
+  inherit [float, 'b, 'c] option ?name ~text ~set ~get ()
   val min = min
   val max = max
 
@@ -236,10 +236,10 @@ let string_of_float x =
   then string ^ "0"
   else string
 
-class ['b] float_entry_option ?name ?(mult=1.1) 
+class ['b, 'c] float_entry_option ?name ?(mult=1.1)
   ~text ~set ~get () =
 object (self)
-  inherit [float, 'b] option ?name ~text ~set ~get ()
+  inherit [float, 'b, 'c] option ?name ~text ~set ~get ()
 
   val mutable entry = None
 
@@ -303,9 +303,9 @@ end
 
 (*******************************************************)
 
-class ['b] float_entry_display ?name ~text ~set ~get () =
+class ['b, 'c] float_entry_display ?name ~text ~set ~get () =
 object (self)
-  inherit [float, 'b] option ?name ~text ~set ~get ()
+  inherit [float, 'b, 'c] option ?name ~text ~set ~get ()
 
   val mutable display = None
 
@@ -337,9 +337,9 @@ end
 
 (*******************************************************)
 
-class ['b] int_entry_display ?name ~text ~set ~get () =
+class ['b, 'c] int_entry_display ?name ~text ~set ~get () =
 object (self)
-  inherit [int, 'b] option ?name ~text ~set ~get ()
+  inherit [int, 'b, 'c] option ?name ~text ~set ~get ()
 
   val mutable display = None
 
@@ -371,9 +371,9 @@ end
 
 (*******************************************************)
 
-class ['b] void_entry_display ?name ~text () =
+class ['b, 'c] void_entry_display ?name ~text () =
 object (self)
-  inherit [unit, 'b] option ?name ~text 
+  inherit [unit, 'b, 'c] option ?name ~text
     ~set:(fun x -> ()) ~get:(fun () -> ())
     ()
 
