--- compiler/ogelf.pas	2019-03-02 14:21:26.692250000 +0000
+++ compiler/ogelf.pas	2019-03-02 14:23:40.598706000 +0000
@@ -1241,7 +1241,7 @@
            { section data }
            layoutsections(datapos);
            { section headers }
-           shoffset:=datapos;
+           shoffset:=align(datapos,dword(Sizeof(AInt)));
            inc(datapos,(nsections+1)*sizeof(telfsechdr));
 
            { Write ELF Header }
@@ -1277,6 +1277,9 @@
            writer.writezeros($40-sizeof(header)); { align }
            { Sections }
            WriteSectionContent(data);
+
+           { Align header }
+           Writer.Writezeros(Align(Writer.Size,Sizeof(AInt))-Writer.Size);
            { section headers, start with an empty header for sh_undef }
            writer.writezeros(sizeof(telfsechdr));
            ObjSectionList.ForEachCall(@section_write_sechdr,nil);
