--- rtl/bsd/ossysc.inc.orig	2015-11-13 21:15:29 UTC
+++ rtl/bsd/ossysc.inc
@@ -282,7 +282,11 @@ begin
  repeat
   novalid:=false;
   CurEntry:=pdirent(dirp^.dd_rewind);
+{$ifdef dragonfly}
+  RecLen:=(CurEntry^.d_namlen + 24) and $FFFFFFF8;
+{$else}
   RecLen:=CurEntry^.d_reclen;
+{$endif}
   if RecLen<>0 Then
    begin {valid direntry?}
     if CurEntry^.d_fileno<>0 then
