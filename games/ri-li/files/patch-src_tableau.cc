--- src/tableau.cc.orig	2007-11-02 11:48:21 UTC
+++ src/tableau.cc
@@ -87,7 +87,7 @@ bool Tableau::Save(void)
   
   // Alloue la mémoire
   Buf=new unsigned char [sizeof(s_Tableau)*N+sizeof(int)+1];
-  if(Buf<=0) return false;
+  if(Buf==NULL) return false;
 
   // Charge les tableaux
   Buf[0]=N/256;
