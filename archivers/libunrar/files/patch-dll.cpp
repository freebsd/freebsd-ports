--- dll.cpp.orig	2010-03-15 06:30:52 UTC
+++ dll.cpp
@@ -281,7 +281,9 @@ int PASCAL ProcessFile(HANDLE hArcData,i
       strcpy(Data->Cmd.Command,Operation==RAR_EXTRACT ? "X":"T");
       Data->Cmd.Test=Operation!=RAR_EXTRACT;
       bool Repeat=false;
-      Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat);
+      
+      if(Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat) == false)
+        return (ERAR_UNKNOWN);
 
       while (Data->Arc.ReadHeader()!=0 && Data->Arc.GetHeaderType()==NEWSUB_HEAD)
       {
