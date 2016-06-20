--- d_main.c.orig	2003-12-08 23:21:25 UTC
+++ d_main.c
@@ -690,6 +690,7 @@ void D_DoomMain(void)
   setbuf(stdout, NULL);
   nomonsters = M_CheckParm("-nomonsters");
   respawnparm = M_CheckParm("-respawn");
+  respawnartifacts = M_CheckParm("-respawnartifacts");
   ravpic = M_CheckParm("-ravpic");
   noartiskip = M_CheckParm("-noartiskip");
   debugmode = M_CheckParm("-debug");
@@ -778,7 +779,13 @@ void D_DoomMain(void)
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
