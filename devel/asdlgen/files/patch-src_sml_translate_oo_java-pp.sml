--- src/sml/translate/oo/java-pp.sml.orig	2000-01-14 02:42:28.000000000 +0100
+++ src/sml/translate/oo/java-pp.sml	2007-10-12 21:02:26.000000000 +0200
@@ -36,7 +36,8 @@
 	  (case qualifier of
 	     [] => NONE
 	   | [""] => SOME {base=base,qualifier=[package_prefix]}
-	   | _ =>  SOME {base=base,qualifier=[package_prefix]@qualifier})
+	   | _ =>  SOME {base=base,qualifier=[package_prefix]@
+					     (map (String.map Char.toLower) qualifier)})
 	fun fix_ty_path {qualifier,base} =
 	  case base of
 	    "java_boolean" => SOME {qualifier=[],base="boolean"}
@@ -280,6 +281,7 @@
 	  end
 	  | pp_cls mn x =
 	  let
+	    val mn = String.map Char.toLower mn
 	    fun get_name (DeclClass x) = PP.fix_tid(#name(x))
 	      | get_name (DeclAbstractClass x) = PP.fix_tid(#name(x))
 	      | get_name _ = raise Error.internal
@@ -311,6 +313,7 @@
 	  
 	fun mk_dep name =
 	  let val mn = ModuleId.toString (PP.fix_mid name)
+	      val mn = String.map Char.toLower mn
 	  in
 	    OS.Path.concat(package_prefix,
  	    OS.Path.concat(mn,
@@ -337,6 +340,7 @@
 	  end
 	  | pp_consts mn x props imports =
 	  let
+	    val mn = String.map Char.toLower mn
 	    val pp =
 	      cat
 	      [str ("package "^package_prefix^"."^mn^";"), nl,
