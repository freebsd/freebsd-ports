--- SeParse.y.orig	Mon Dec 29 07:24:02 2003
+++ SeParse.y	Mon Dec 29 07:28:38 2003
@@ -81,19 +81,19 @@
 {
   char long_line[1000];
 
-  char input_str[] = "This(is, a, real, funky); script();
-            Scripts(); Can(be); Multi(Line, \"Can't they?\");
-            Commas(are, no, longer, optional, inside, arglists);
-	    Scripts(); Can(); contain(\"tabs \\t and backspaces \\b\");
-	    As(\"Well\\ as Quoted Strings\", and, '\"Quoted Strings inside
-	    quoted strings\"');
-	esc(can, appear, outside, strings, ^z, \\012\\015\\n);
-	    But(parenthesis, should, match);
-  We(\"have a funny way of specifying \\012 chars and even)\"); 
-	backslashes( \" \\\\ \");
-  new(\"in this version are ^m and ^A ctr-escapes, as in ^S^Q\");
- The(next, line, will, give, a, syntax, error, because, it, has, two, adj, functions,
-	without, a, separating, semicolon);
+  char input_str[] = "This(is, a, real, funky); script();\n\
+            Scripts(); Can(be); Multi(Line, \"Can't they?\");\n\
+            Commas(are, no, longer, optional, inside, arglists);\n\
+	    Scripts(); Can(); contain(\"tabs \\t and backspaces \\b\");\n\
+	    As(\"Well\\ as Quoted Strings\", and, '\"Quoted Strings inside\n\
+	    quoted strings\"');\n\
+	esc(can, appear, outside, strings, ^z, \\012\\015\\n);\n\
+	    But(parenthesis, should, match);\n\
+  We(\"have a funny way of specifying \\012 chars and even)\"); \n\
+	backslashes( \" \\\\ \");\n\
+  new(\"in this version are ^m and ^A ctr-escapes, as in ^S^Q\");\n\
+ The(next, line, will, give, a, syntax, error, because, it, has, two, adj, functions,\n\
+	without, a, separating, semicolon);\n\
  End() script()";
 
   printf("------ String to parse: \n%s\n\n---- Parsing begins:\n", input_str);
