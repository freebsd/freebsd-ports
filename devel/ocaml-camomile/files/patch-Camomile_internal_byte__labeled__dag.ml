--- Camomile/internal/byte_labeled_dag.ml.orig	2019-08-08 07:10:33 UTC
+++ Camomile/internal/byte_labeled_dag.ml
@@ -87,7 +87,7 @@ let make_bytes def vs =
           branch.(Char.code c') <- Some node;
           scan d c leaf branch rest
   in
-  let comp (s1, _) (s2, _) = Pervasives.compare s1 s2 in
+  let comp (s1, _) (s2, _) = Stdlib.compare s1 s2 in
   let vs = List.sort comp vs in
   match vs with
     (_, _) :: _ ->
