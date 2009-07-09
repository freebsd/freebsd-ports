--- extract.cpp.orig	2009-06-30 09:18:53.000000000 +0300
+++ extract.cpp	2009-07-09 10:02:21.000000000 +0300
@@ -354,6 +354,7 @@
     char CurVolName[NM];
     strcpy(CurVolName,ArcName);
 
+    if(strcmp(ArcName,"")==0) return(false);
     VolNameToFirstName(ArcName,ArcName,(Arc.NewMhd.Flags & MHD_NEWNUMBERING)!=0);
     if (stricomp(ArcName,CurVolName)!=0 && FileExist(ArcName))
     {
