--- gconf/gconf-internals.c.orig	Tue Apr 20 01:24:46 2004
+++ gconf/gconf-internals.c	Tue Apr 20 01:24:56 2004
@@ -2839,7 +2839,6 @@
                        GError  **error)
 {
   ConfigServer server = CORBA_OBJECT_NIL;
-;
   int p[2] = { -1, -1 };
   char buf[1];
   GError *tmp_err;
