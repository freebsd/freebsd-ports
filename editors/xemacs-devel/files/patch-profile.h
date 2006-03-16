Index: src/profile.h
===================================================================
RCS file: /pack/xemacscvs/XEmacs/xemacs/src/profile.h,v
retrieving revision 1.3
retrieving revision 1.4
diff -u -r1.3 -r1.4
--- src/profile.h	2005/10/25 11:16:27	1.3
+++ src/profile.h	2006/03/14 19:31:43	1.4
@@ -113,6 +113,7 @@
   RETURN_EXIT_PROFILING (tag, Lisp_Object, expr)
   
 #define RETURN_UNGCPRO_EXIT_PROFILING(tag, expr)	\
+do							\
 {							\
   Lisp_Object ret_ungc_val = (expr);			\
   UNGCPRO;						\
