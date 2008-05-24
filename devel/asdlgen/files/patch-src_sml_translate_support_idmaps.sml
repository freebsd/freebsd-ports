--- src/sml/translate/support/idmaps.sml.orig	1999-09-13 00:27:25.000000000 +0200
+++ src/sml/translate/support/idmaps.sml	2007-10-12 18:43:12.000000000 +0200
@@ -102,15 +102,17 @@
 	 struct
 	   val id_map =
 	     List.map (fix_kw "_")
-	     ["abstract","boolean", "break", "byte", "case", "char",
-	      "class", "const", "continue", "do", "double", "else",
-	      "extends", "final","finally", "int", "float", "for",
-	      "default", "if", "implements", "import", "instanceof",
-	      "interface", "long", "native", "new", "public",
-	      "short", "super", "switch", "synchroinized", "package",
-	      "private", "protected", "transient", "return", "void",
-	      "static", "while", "throw", "throws", "try",
-	      "volatile","kind"]
+	     ["abstract", "assert", "boolean", "break", "byte",
+	      "case", "catch", "char", "class", "const", "continue",
+	      "default", "do", "double", "else", "enum", "extends",
+	      "final", "finally", "float", "for", "goto", "if",
+	      "implements", "import", "instanceof", "int",
+	      "interface", "long", "native", "new", "package",
+	      "private", "protected", "public", "return", "short",
+	      "static", "strictfp", "super", "switch",
+	      "synchronized", "this", "throw", "throws",
+	      "transient", "try", "void", "volatile", "while",
+	      "kind"]
 	     
 	   val ty_map = id_map 
 	   val name = "Java"
@@ -129,4 +131,4 @@
 	   val name = "Icon"
 	 end
 		   
-    end
\ No newline at end of file
+    end
