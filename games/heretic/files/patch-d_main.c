--- d_main.c.ori	Sun Mar 11 16:31:49 2007
+++ d_main.c	Sun Mar 11 16:33:46 2007
@@ -690,6 +690,7 @@
   setbuf(stdout, NULL);
   nomonsters = M_CheckParm("-nomonsters");
   respawnparm = M_CheckParm("-respawn");
+  respawnartifacts = M_CheckParm("-respawnartifacts");
   ravpic = M_CheckParm("-ravpic");
   noartiskip = M_CheckParm("-noartiskip");
   debugmode = M_CheckParm("-debug");
@@ -778,7 +779,13 @@
     {
       deathmatch = true;
     }
-  
+
+  if ( M_CheckParm("-respawnartifacts")!=0 )
+    {
+     printf("Parameter: -respawnartifacts\n");
+     respawnartifacts=1;
+    }
+
   p = M_CheckParm("-skill");
   if(p && p < myargc-1)
     {
