diff -ruN unrar.orig/dll.cpp unrar/dll.cpp
+++ dll.cpp
@@ -59,8 +59,8 @@
     }
     if (!Data->Arc.IsArchive(false))
     {
-      delete Data;
       r->OpenResult=Data->Cmd.DllError!=0 ? Data->Cmd.DllError:ERAR_BAD_ARCHIVE;
+      delete Data;
       return(NULL);
     }
     r->Flags=Data->Arc.NewMhd.Flags;
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
