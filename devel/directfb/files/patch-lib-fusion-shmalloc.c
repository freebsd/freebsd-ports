--- lib/fusion/shmalloc.c.orig	2012-05-23 13:43:12 UTC
+++ lib/fusion/shmalloc.c
@@ -52,6 +52,8 @@
 
 D_DEBUG_DOMAIN( Fusion_SHM, "Fusion/SHM", "Fusion Shared Memory" );
 
+typedef unsigned long ulong;
+
 void
 fusion_dbg_print_memleaks( FusionSHMPoolShared *pool )
 {
