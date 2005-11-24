Index: src/mule-coding.c
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/mule-coding.c,v
retrieving revision 1.35
retrieving revision 1.36
diff -u -r1.35 -r1.36
--- src/mule-coding.c	2005/06/19 21:08:31	1.35
+++ src/mule-coding.c	2005/11/22 07:19:32	1.36
@@ -2643,10 +2643,10 @@
 	write_c_string (printcharfun, "(force)");
     }
 
-#define FROB(prop)					\
-  if (!NILP (iso2022_getprop (cs, prop)))		\
-    {							\
-      write_fmt_string (printcharfun, ", %s", prop);	\
+#define FROB(prop)					        \
+  if (!NILP (iso2022_getprop (cs, prop)))		        \
+    {						                \
+      write_fmt_string_lisp (printcharfun, ", %s", 1, prop);	\
     }
   
   FROB (Qshort);
