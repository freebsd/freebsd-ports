--- main.c.orig	Thu Jul  8 18:24:25 2004
+++ main.c	Thu Jul  8 18:25:02 2004
@@ -355,7 +355,9 @@
   end_program(436);
   } 
 lir_errors:;
+#if 0
 if(ui.memlock == 0)munlockall();
+#endif
 close_all_except_vga();
 if(lir_status > LIR_OK)
   {
@@ -640,7 +642,9 @@
     {
 bufreduce:;
     vga_clear();
+#if 0
     if(ui.memlock == 0)munlockall();
+#endif
     settextcolor(15);
     switch (lir_status)
       {
@@ -854,12 +858,14 @@
   else
     {
     if(chr != 'Y')goto gtswap;
+#if 0
     if(mlockall(MCL_CURRENT) != 0)
       {
       if(errno == EPERM)end_program(1168);
       if(errno == ENOMEM)end_program(1169);
       end_program(1170); 
       }
+#endif
     }  
   clearscreen();
   printf("Use usleep when the CPU is not needed\nRead z_USLEEP.txt for info.");
