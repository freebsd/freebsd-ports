--- cad_source/zcad/uzcsysinfo.pas.orig	2017-05-01 09:49:45 UTC
+++ cad_source/zcad/uzcsysinfo.pas
@@ -196,6 +196,7 @@ begin
      debugln('{N}SysParam.ProgramPath="%s"',[ProgramPath]);
      //programlog.LogOutStr(format('SysParam.ProgramPath="%s"',[ProgramPath]),lp_OldPos,LM_Necessarily);
      debugln('{N}SysParam.TempPath="%s"',[TempPath]);
+     debugln('{N}SysParam.UserPath="%s"',[UserPath]);
      //programlog.LogOutStr(format('SysParam.TempPath="%s"',[TempPath]),lp_OldPos,LM_Necessarily);
      debugln('{N}SysParam.ScreenX=%d',[SysParam.ScreenX]);
      //programlog.LogOutStr(format('SysParam.ScreenX=%d',[SysParam.ScreenX]),lp_OldPos,LM_Necessarily);
