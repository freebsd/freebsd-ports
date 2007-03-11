--- extArray.mli	2005/11/25 10:22:10	1.11
+++ extArray.mli	2006/10/11 16:24:42	1.12
@@ -35,6 +35,13 @@
   val rev_in_place : 'a array -> unit
     (** In-place array reversal.  The array argument is updated. *)
 
+  val iter2 : ('a -> 'b -> unit) -> 'a array -> 'b array -> unit
+    (** [Array.iter2 f [|a1; ...; an|] [|b1; ...; bn|]] performs
+    calls [f a1 b1; ...; f an bn] in that order.
+    
+    @raise Invalid_argument if the length of [a1] does not equal the
+    length of [a2]. *)
+
   val for_all : ('a -> bool) -> 'a array -> bool
     (** [for_all p [a1; ...; an]] checks if all elements of the array
 	satisfy the predicate [p].  That is, it returns
