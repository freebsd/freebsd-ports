diff -ruN unrar.orig/dll.cpp unrar/dll.cpp
--- dll.cpp.orig       2005-08-03 20:34:30.000000000 +0400
+++ dll.cpp    2006-01-11 12:13:33.000000000 +0300
@@ -271,8 +271,10 @@
       strcpy(Data->Cmd.Command,Operation==RAR_EXTRACT ? "X":"T");
       Data->Cmd.Test=Operation!=RAR_EXTRACT;
       bool Repeat=false;
-      Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat);
-
+      
+      if(Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat) == false)
+        return (ERAR_UNKNOWN);
+
       while (Data->Arc.ReadHeader()!=0 && Data->Arc.GetHeaderType()==NEWSUB_HEAD)
       {
         Data->Extract.ExtractCurrentFile(&Data->Cmd,Data->Arc,Data->HeaderSize,Repeat);
