--- make/src/main.cc.orig	2023-01-13 17:33:36 UTC
+++ make/src/main.cc
@@ -128,6 +128,9 @@ extern void job_adjust_fini();
 /*
  * typedefs & structs
  */
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif	/* __FreeBSD__ */
 
 /*
  * Static variables
