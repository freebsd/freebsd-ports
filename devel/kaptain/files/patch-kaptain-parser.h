--- kaptain/parser.h.orig	Wed Aug 14 12:26:33 2002
+++ kaptain/parser.h	Fri Dec 20 16:14:31 2002
@@ -5,15 +5,15 @@
 typedef union
 {
   int integer;
-  string * pstring;
+  std::string * pstring;
   Rule * prule;
   Disjunction * pdisjunction;
   Conjunction * pconjunction;
   Parameter * pparameter;
-  list<Parameter *> * pparamlist;
-  string * string_array[3];
-  list<string *> * pstringlist;
-  list<Parameter *> * ptrafolist;
+  std::list<Parameter *> * pparamlist;
+  std::string * string_array[3];
+  std::list<std::string *> * pstringlist;
+  std::list<Parameter *> * ptrafolist;
 } yystype;
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
