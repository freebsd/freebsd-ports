--- objects/script.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ objects/script.c	2007-12-17 19:00:06.000000000 +0100
@@ -442,7 +442,7 @@
 ay_script_writecb(FILE *fileptr, ay_object *o)
 {
  ay_script_object *sc = NULL;
- char *arrname = NULL, *membername = NULL, *memberval = NULL;
+ const char *arrname = NULL, *membername = NULL, *memberval = NULL;
  char *arrnameend = NULL;
  Tcl_Obj *arrmemberlist = NULL, *arrmember;
  int arrmembers = 0, i, slen;
