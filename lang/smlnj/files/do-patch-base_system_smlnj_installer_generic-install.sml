--- base/system/smlnj/installer/generic-install.sml.orig	2014-08-23 04:18:09.000000000 +0200
+++ base/system/smlnj/installer/generic-install.sml	2014-08-28 21:51:06.000000000 +0200
@@ -233,28 +233,26 @@
 	(* ------------------------------ *)
 
 	(* parse the targets file *)
-	fun loop (ml, srcReqs, allsrc) =
+	fun loop (ml, allsrc) =
 	    case getInputTokens s of
-		NONE => (TextIO.closeIn s; (ml, srcReqs, allsrc))
+		NONE => (TextIO.closeIn s; (ml, allsrc))
 	      | SOME [x as ("dont_move_libraries" | "move_libraries")] =>
   		  (warn ["\"", x, "\" no longer supported",
 			 " (installer always moves libraries)\n"];
-		   loop (ml, srcReqs, allsrc))
-	      | SOME ["request", "src-smlnj"] => loop (ml, srcReqs, true)
-	      | SOME ["request", module] => if SS.member(allmoduleset, module)
-		  then loop (ml, module :: srcReqs, allsrc)
-		  else loop (module :: ml, srcReqs, allsrc)
-	      | SOME [] => loop (ml, srcReqs, allsrc)
+		   loop (ml, allsrc))
+	      | SOME ["request", "src-smlnj"] => loop (ml, true)
+	      | SOME ["request", module] => loop (module :: ml, allsrc)
+	      | SOME [] => loop (ml, allsrc)
 	      | SOME l => fail ["ill-formed targets line: ", tokenLine l, "\n"]
 
-	val (modules, srcReqs, allsrc) = loop ([], [], false)
+	val (modules, allsrc) = loop ([], false)
 
 	(* now resolve dependencies; get full list of modules
 	 * in correct build order: *)
 	val modules = resolve (modules, depfile)
 	val moduleset = SS.addList (SS.empty, modules)
 	val srcmoduleset = if allsrc then SS.union (moduleset, allmoduleset)
-			   else SS.addList (moduleset, srcReqs)
+			   else moduleset
 
 	(* fetch and unpack source trees, using auxiliary helper command
 	 * which takes the root directory as its first and the module
@@ -386,7 +384,8 @@
 		      salist := (fn () => standalone args) :: (!salist)
 	    in case SM.find (actions, module) of
 		   SOME al => app perform (rev al)
-		 | NONE => fail ["unknown module: ", module, "\n"]
+		 | NONE => if SS.member(allmoduleset, module) then ()
+		           else fail ["unknown module: ", module, "\n"]
 	    end
     in
 	(command_pathconfig "bindir";	(* dummy -- for CM make tool *)
