--- client/le_util.c.orig	2005-01-12 05:19:36 UTC
+++ client/le_util.c
@@ -4,6 +4,7 @@
 
 int	localent_count = 0;
 
+localent_t cl_localents[MAX_LOCAL_ENTS];
 cvar_t	*cl_lents;
 
 void LE_RunEntity (localent_t *ent);
