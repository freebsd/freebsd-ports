--- def.h.orig	2016-09-01 15:30:59 UTC
+++ def.h
@@ -328,6 +328,8 @@ struct undo_rec {
  * Prototypes.
  */
 
+void		*reallocarray(void*, size_t, size_t);
+
 /* tty.c X */
 void		 ttinit(void);
 void		 ttreinit(void);
