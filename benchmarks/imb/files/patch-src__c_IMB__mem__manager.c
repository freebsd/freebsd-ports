--- src_c/IMB_mem_manager.c.orig	2026-06-21 10:42:08 UTC
+++ src_c/IMB_mem_manager.c
@@ -424,7 +424,7 @@ ------------------------------------------------------
     IMB_i_alloc(int, c_info->g_ranks, c_info->w_num_procs, "Init_Pointers 1");
     IMB_i_alloc(int, c_info->g_sizes, c_info->w_num_procs, "Init_Pointers 2");
 
-#if (defined MPI1 || defined NBC || defined MPI4)
+#if (defined MPI1 || defined NBC || defined MPI4 || defined MPIIO)
     IMB_i_alloc(int, c_info->sndcnt, c_info->w_num_procs, "Init_Pointers 3");
     IMB_i_alloc(int, c_info->sdispl, c_info->w_num_procs, "Init_Pointers 4");
 
