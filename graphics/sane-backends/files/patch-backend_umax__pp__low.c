--- backend/umax_pp_low.c.orig	2019-10-09 14:50:00 UTC
+++ backend/umax_pp_low.c
@@ -939,6 +939,10 @@ sanei_umax_pp_initPort (int port, char *name)
   int found = 0;
   int fd;
 # endif
+# ifdef HAVE_DEV_PPBUS_PPI_H
+  int found = 0;
+  int fd;
+# endif
 # ifdef HAVE_IOPERM
   int ectr;
 # endif
