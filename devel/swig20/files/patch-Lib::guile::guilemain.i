Index: SWIG/Lib/guile/guilemain.i
diff -u SWIG/Lib/guile/guilemain.i:1.4 SWIG/Lib/guile/guilemain.i:1.4.2.1
--- Lib/guile/guilemain.i:1.4	Sun Sep  3 15:06:32 2000
+++ Lib/guile/guilemain.i	Mon Feb 26 11:57:56 2001
@@ -27,6 +27,10 @@
 %{
 #include <libguile.h>
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 /* Debugger interface (don't change the order of the following lines) */
 #define GDB_TYPE SCM
 #include <libguile/gdb_interface.h>
@@ -43,6 +47,10 @@
   scm_shell(argc, argv);	/* scheme interpreter */
   /* never reached: scm_shell will perform an exit */
 }
+
+#ifdef __cplusplus
+}
+#endif
 
 int
 main(int argc, char **argv)
