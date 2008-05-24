--- src/sml/util/misc/file-set.sml.orig	2000-01-14 02:42:30.000000000 +0100
+++ src/sml/util/misc/file-set.sml	2007-09-28 22:50:55.000000000 +0200
@@ -68,11 +68,18 @@
 	fun libPath x = d@x
 	fun get_node "" = NONE
 	  | get_node x = OM.find(fs',x)
-	fun fix_dep x = case OM.find(fs',x) of 
-	  (SOME (L _)) => libPath [x] | _ => [x]
-	fun cvt (F x) = {name=[#name x],
+	fun fix_dep x = let open OS.Path
+			    val xarcs = (#arcs o fromString) x
+			in case OM.find(fs',x) of 
+	  (SOME (L _)) => libPath xarcs | _ => xarcs
+			end
+	fun cvt (F x) = let open OS.Path
+			    val xarcs = (#arcs o fromString) (#name x)
+			in
+			{name=xarcs,
 			 depends=List.map fix_dep (#depends x),
 			 body=(#body x)}
+			end
 	  | cvt _ = raise (Fail "impossible")
 
 	fun prefix_it {name,depends,body} =
@@ -90,4 +97,4 @@
 	val components = Scc.topOrder {root="",follow=follow}
       in List.foldl no_cycle [] components
       end
-  end
\ No newline at end of file
+  end
