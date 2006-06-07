--- extract.cpp.orig	Wed Jun  7 08:52:35 2006
+++ extract.cpp	Wed Jun  7 08:55:35 2006
@@ -291,6 +291,7 @@
     char CurVolName[NM];
     strcpy(CurVolName,ArcName);
 
+    if(strcmp(ArcName,"")==0) return(false);
     VolNameToFirstName(ArcName,ArcName,(Arc.NewMhd.Flags & MHD_NEWNUMBERING));
     if (stricomp(ArcName,CurVolName)!=0 && FileExist(ArcName))
     {
