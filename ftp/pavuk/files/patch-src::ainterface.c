--- src/ainterface.c.orig	Wed Nov  3 15:51:10 2004
+++ src/ainterface.c	Fri Nov 12 03:29:00 2004
@@ -448,13 +448,17 @@
 {
   int i;
 
+#ifdef I_FACE
+#ifdef HAVE_MT
+  _config_struct_priv_t privcfg;
+#endif
+#endif
+
   if(cfg.mode == MODE_MIRROR)
     return;
 
 #ifdef I_FACE
 #ifdef HAVE_MT
-  _config_struct_priv_t privcfg;
-
   privcfg_make_copy(&privcfg);
   pthread_setspecific(cfg.privcfg_key, (void *) (&privcfg));
   pthread_cleanup_push((void *) privcfg_free, (void *) (&privcfg));
