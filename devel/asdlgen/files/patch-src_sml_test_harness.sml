--- src/sml/test/harness.sml.orig	2001-10-02 16:20:32.000000000 +0200
+++ src/sml/test/harness.sml	2007-10-07 20:09:45.000000000 +0200
@@ -69,15 +69,15 @@
 	val c_includes =  (mk_path ["c"])@   ["/usr/local/include"]
 	val c_libs =  mk_path ["c"]@ ["/usr/local/lib"]
 
-	val cxx_includes = mk_path ["c"]
-	val cxx_libs = mk_path ["cxx"]
+	val cxx_includes = (mk_path ["cxx"])@ ["/usr/local/include"]
+	val cxx_libs = mk_path ["cxx"]@ ["/usr/local/lib"]
 
 	val java_classes = [] (*mk_path ["java"]*)
 
 	val cm_path = [] (* mk_path ["sml","base"]*)
 	val icon_ucode = [] (* mk_path ["icon"] *)
 	val haskell_path = (* (mk_path ["haskell"])@*)
-	  ["/usr/share/hugs/lib"]
+	  [ (*"/usr/share/hugs/lib"*) ]
 	val ocaml_path = [] (* (mk_path ["ocaml"]) *)
     end
 
@@ -208,7 +208,7 @@
 		val sigs = (get_files "sml" i)
 		val outs = strs@sigs
 		val cm_path = S.cm_path
-	    in P.sml_batch{cm_path=cm_path,inputs="smlnj-lib.cm"::outs}
+	    in P.sml_batch{cm_path=cm_path,inputs="$/smlnj-lib.cm"::outs}
 	    end
 
 	fun ocaml_comp i =
@@ -295,9 +295,9 @@
 	      mk_path ["modTest","pos.asdl"]]) 
 
 	val big_int_test =
-	    (test_all "generic.asdl"  [mk_path ["generic.asdl"]])
+	    (test_all "generic.asdl"  [mk_path ["..","generic.asdl"]])
 	val asdl_test =
-	    (test_all "asdl.asdl"  [mk_path ["asdl.asdl"]])
+	    (test_all "asdl.asdl"  [mk_path ["..","asdl.asdl"]])
 
 	val pattern_test =
 	    (test_all "pattern.asdl"  [mk_path ["pattern.asdl"]])
