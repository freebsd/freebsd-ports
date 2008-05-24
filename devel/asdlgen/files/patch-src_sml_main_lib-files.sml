--- src/sml/main/lib-files.sml.orig	2000-02-10 19:51:47.000000000 +0100
+++ src/sml/main/lib-files.sml	2007-10-11 17:41:21.000000000 +0200
@@ -58,23 +58,23 @@
       fun join (x,y) = OS.Path.concat("asts",OS.Path.concat(x,y))
 
       val std_pkl_lib =
-	FileSet.mkLib {name=join("StdPkl","g.java"),depends=[],impl=
+	FileSet.mkLib {name=join("stdpkl","g.java"),depends=[],impl=
         MkFileSet.file_set (mkroot ["java"]) FileSet.empty
-	  [(join("StdPkl","g.java"),[]),
-	   (join("StdPkl","PklJava.java"),[join("StdPkl","g.java")])]}
+	  [(join("stdpkl","g.java"),[]),
+	   (join("stdpkl","PklJava.java"),[join("stdpkl","g.java")])]}
 
       val std_prims_lib =
-	FileSet.mkLib {name=join("StdPrims","g.java"),
-		    depends=[join("StdPkl","g.java")],impl=
+	FileSet.mkLib {name=join("stdprims","g.java"),
+		    depends=[join("stdpkl","g.java")],impl=
         MkFileSet.file_set (mkroot ["java"]) FileSet.empty
-	 [(join("StdPrims","g.java"),[join("StdPkl","g.java")]),
-	  (join("StdPrims","identifier.java"),[join("StdPrims","g.java")])]}
+	 [(join("stdprims","g.java"),[join("stdpkl","g.java")]),
+	  (join("stdprims","identifier.java"),[join("stdprims","g.java")])]}
 
       val std_types_lib =
-	FileSet.mkLib {name=join("StdTypes","g.java"),
-		    depends=[join("StdPkl","g.java")],impl=
+	FileSet.mkLib {name=join("stdtypes","g.java"),
+		    depends=[join("stdpkl","g.java")],impl=
         MkFileSet.file_set (mkroot ["java"]) FileSet.empty
-	 [(join("StdTypes","g.java"),[])]}
+	 [(join("stdtypes","g.java"),[])]}
     in val java = add_files [std_pkl_lib,std_prims_lib,std_types_lib]
     end
     local
