diff -urN ../SWIG1.3a5/Lib/guile/guilemain.i ./Lib/guile/guilemain.i
--- ../SWIG1.3a5/Lib/guile/guilemain.i	Sun Sep  3 15:06:32 2000
+++ ./Lib/guile/guilemain.i	Tue Feb 27 06:12:33 2001
@@ -7,7 +7,7 @@
 *   Wrapper and Interface Generator (SWIG 1.1)
 *
 * - Automatic Version Information via RCS/CVS:
-*   $Id: guilemain.i,v 1.4 2000/09/03 20:06:32 mkoeppe Exp $
+*   $Id: guilemain.i,v 1.4.2.1 2001/02/26 17:57:56 mkoeppe Exp $
 *   $Source: /cvs/projects/SWIG/Lib/guile/guilemain.i,v $
 *
 * This program is free software; you can redistribute it and/or modify
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
