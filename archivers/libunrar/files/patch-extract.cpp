--- extract.cpp.orig	2010-03-15 06:30:52 UTC
+++ extract.cpp
@@ -354,6 +354,7 @@ bool CmdExtract::ExtractCurrentFile(Comm
     char CurVolName[NM];
     strcpy(CurVolName,ArcName);
 
+    if(strcmp(ArcName,"")==0) return(false);
     VolNameToFirstName(ArcName,ArcName,(Arc.NewMhd.Flags & MHD_NEWNUMBERING)!=0);
     if (stricomp(ArcName,CurVolName)!=0 && FileExist(ArcName))
     {
