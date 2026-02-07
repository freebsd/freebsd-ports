--- main.c.orig	1996-11-16 05:37:16 UTC
+++ main.c
@@ -66,7 +66,7 @@ int checkOption(argc,argv)
   /***  set s_map  ***/
   gameMainFlg.s_map = False;
   nowDataRec.nowMap.gameSpeed = 90;
-  nowDataRec.nowMap.dirname[0] == 0x00;
+  strcpy(nowDataRec.nowMap.dirname, "/usr/local/lib/X11/xdeblock/mapf");
 
   for(i =1; i  < argc; i++)
     {
