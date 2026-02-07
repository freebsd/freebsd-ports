--- src/clean.c.orig	2005-10-24 11:48:52 UTC
+++ src/clean.c
@@ -34,7 +34,7 @@
 /*------------------------------- variables ---------------------------------*/
 
 static LONG		*cleanvictim;
-
+objliststruct		*cleanobjlist;
 
 /******************************* initclean **********************************
 PROTO   void initclean(void)
