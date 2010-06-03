--- lib/fusion/shmalloc.c
+++ lib/fusion/shmalloc.c
@@ -52,6 +52,8 @@
 
 D_DEBUG_DOMAIN( Fusion_SHM, "Fusion/SHM", "Fusion Shared Memory" );
 
+typedef unsigned long ulong;
+
 void
 fusion_dbg_print_memleaks( FusionSHMPoolShared *pool )
 {
