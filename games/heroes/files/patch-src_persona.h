--- src/persona.h.orig	2001-09-21 10:43:54 UTC
+++ src/persona.h
@@ -28,8 +28,8 @@
  * difference only if the program has a sgid or suid bit.
  */
 
-bool keep_sgid;			/* Whether we should keep the  */
-bool keep_suid;			/* SGID or SUID priviledge. */
+extern bool keep_sgid;			/* Whether we should keep the  */
+extern bool keep_suid;			/* SGID or SUID priviledge. */
 
 /* Get information about the current persona,
    and switch to the user persona.  */
