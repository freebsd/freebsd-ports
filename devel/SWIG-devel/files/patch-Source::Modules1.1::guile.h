Index: SWIG/Source/Modules1.1/guile.h
diff -u SWIG/Source/Modules1.1/guile.h:1.15 SWIG/Source/Modules1.1/guile.h:1.15.2.2
--- Source/Modules1.1/guile.h:1.15	Tue Sep 19 09:50:15 2000
+++ Source/Modules1.1/guile.h	Thu Mar  1 18:28:02 2001
@@ -36,10 +36,18 @@
     GUILE_LSTYLE_HOBBIT                 // use (hobbit4d link)
   } linkage;
   File  *procdoc;
+  enum {
+    GUILE_1_4,
+    PLAIN,
+    TEXINFO
+  } docformat;
   int	 emit_setters;
   int    struct_member;
+  String *before_return;
   void   emit_linkage(char *module_name);
-
+  void   write_doc(const String *proc_name,
+		   const String *signature,
+		   const String *doc);
 public :
   GUILE ();
   void parse_args (int, char *argv[]);
@@ -54,6 +62,7 @@
   void set_init (char *);
   void create_command (char *, char *) { };
   void cpp_variable(char *name, char *iname, SwigType *t);
+  void pragma(char *lang, char *cmd, char *value);
 };
 
 /* guile.h ends here */
