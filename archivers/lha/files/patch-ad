--- src/lharc.c.orig   Sun May  7 00:05:29 2000
+++ src/lharc.c        Fri Jul 28 19:35:31 2000
@@ -889,6 +889,7 @@
 /*                                                                                                                                                    */
 /* ------------------------------------------------------------------------ */
 /* Build temporary file name and store to TEMPORARY_NAME */
+#if !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 void
 build_temporary_name()
 {
@@ -912,7 +913,7 @@
       mktemp(temporary_name);
 #endif
 }
-
+#endif
 /* ------------------------------------------------------------------------ */
 static void
 modify_filename_extention(buffer, ext)
