--- agraph.ml.orig	2007-03-07 22:53:54.000000000 +0100
+++ agraph.ml	2010-08-25 13:13:33.000000000 +0200
@@ -50,8 +50,9 @@ let dot_format params agraph =
       agraph.nodes in
 
   !+ "digraph \"monotone-viz\"\n{\n" ;
-  if params.lr_layout then
-    !+ "  graph [rankdir=LR] ;\n" ;
+  if params.lr_layout
+  then  !+ "  graph [rankdir=LR] ;\n"
+  else  !+ "  graph [rankdir=BT] ;\n" ;
   !+ "  graph [ranksep=\"0.25\"] ;\n" ;
   !+ "  node [label=\"\"] ;\n" ;
   
@@ -222,11 +223,11 @@ let spawn_dot graph status done_cb =
   let dot_prg = graph.layout_params.dot_program in
   let cmd = 
     if Viz_misc.debug "dot"
-    then [ "/bin/sh" ; "-c" ; 
+    then [ "/usr/local/bin/bash" ; "-c" ; 
 	   Printf.sprintf 
 	     "set -o pipefail ; \
-              tee agraph.in.dot | %s -q -y -s%.0f | tee agraph.out.dot" dot_prg ppi ]
-    else [ dot_prg ; "-q" ; "-y" ; Printf.sprintf "-s%.0f" ppi ] in
+              tee agraph.in.dot | %s -q -s%.0f | tee agraph.out.dot" dot_prg ppi ]
+    else [ dot_prg ; "-q" ; Printf.sprintf "-s%.0f" ppi ] in
   let error fmt =
     Printf.kprintf (fun s -> done_cb (`LAYOUT_ERROR s)) fmt in
   try
