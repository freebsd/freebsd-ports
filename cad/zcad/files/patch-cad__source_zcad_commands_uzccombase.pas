--- cad_source/zcad/commands/uzccombase.pas.orig	2017-05-01 09:49:51 UTC
+++ cad_source/zcad/commands/uzccombase.pas
@@ -332,7 +332,14 @@ begin
      itautoseve:=false;
      if operands='QS' then
                           begin
+{$IFDEF UNIX}
+                               // On Unix, force saving under ~/.zcad/autosave
+                               s1:=sysvar.SAVE.SAVE_Auto_FileName^;
+                               if s1[1]='*' then
+                                   s1:=UserPath+copy(s1,2,length(s1)-1);
+{$ELSE}
                                s1:=ExpandPath(sysvar.SAVE.SAVE_Auto_FileName^);
+{$ENDIF}
                                s:=rsAutoSave+': '''+s1+'''';
                                HistoryOutStr(s);
                                itautoseve:=true;
