diff -ruN unrar.orig/dll.cpp unrar/dll.cpp
+++ dll.cpp
@@ -272,7 +272,9 @@
       strcpy(Data->Cmd.Command,Operation==RAR_EXTRACT ? "X":"T");
       Data->Cmd.Test=Operation!=RAR_EXTRACT;
       bool Repeat=false;
-      Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat);
+      
+      if(Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat) == false)
+        return (ERAR_UNKNOWN);
 
       while (Data->Arc.ReadHeader()!=0 && Data->Arc.GetHeaderType()==NEWSUB_HEAD)
       {
