--- ./Modules/selectmodule.c.orig	2013-11-30 23:03:20.030929248 +1100
+++ ./Modules/selectmodule.c	2013-11-30 23:03:56.111022639 +1100
@@ -1246,7 +1246,7 @@
     PyObject *pfd;
     static char *kwlist[] = {"ident", "filter", "flags", "fflags",
                              "data", "udata", NULL};
-    static char *fmt = "O|hhi" INTPTRT_FMT_UNIT UINTPTRT_FMT_UNIT ":kevent";
+    static char *fmt = "O|hHI" INTPTRT_FMT_UNIT UINTPTRT_FMT_UNIT ":kevent";
 
     EV_SET(&(self->e), 0, EVFILT_READ, EV_ADD, 0, 0, 0); /* defaults */
 
