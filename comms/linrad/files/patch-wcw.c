--- wcw.c.orig	Thu Jul  8 18:22:12 2004
+++ wcw.c	Thu Jul  8 18:22:55 2004
@@ -116,10 +116,12 @@
 int syncflag, baseb_graph_time;
 audio_buf_info ad_info, ad_info2;
 touch_stack();
+#if 0
 if(ui.memlock == 0)
   {
   if(mlockall(MCL_CURRENT) != 0)end_program(1165);
   }
+#endif
 baseb_graph_time=0;
 get_buffers(0);
 if(lir_status != LIR_OK)return;
@@ -181,10 +183,12 @@
 diskread_timer=recent_time;
 latest_idle_time=recent_time;
 lirsta=RX_LOW_PRIO;
+#if 0
 if(ui.memlock == 0)
   {
   if(mlockall(MCL_CURRENT) != 0)lir_status=LIR_MEMERR;
   }
+#endif
 if(lir_status != LIR_OK)goto wcw_exit;
 // *******************************************************
 //                   MAIN RECEIVE LOOP
