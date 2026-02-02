--- source/about.pas.orig	2026-01-30 17:33:07 UTC
+++ source/about.pas
@@ -120,7 +120,7 @@ begin
   Caption := f_('About %s', [APPNAME]);
   lblAppName.Caption := APPNAME;
   lblAppVersion.Caption := _('Version') + ' ' + Mainform.AppVersion;
-  lblAppCompiled.Caption := _('Compiled on:') + ' ' + DateTimeToStr(GetFileModTime(Application.ExeName)) + ' with';
+  lblAppCompiled.Caption := _('Compiled on:') + ' ' + DateTimeToStr(GetFileModTime({$IFDEF FREEBSD}'/usr/local/bin/'+{$ENDIF}Application.ExeName)) + ' with';
   lnklblCompiler.Caption := GetCompilerVersion;
   lnklblCompiler.Hint := 'https://www.lazarus-ide.org/?utm_source='+APPNAME;
   lnklblWebpage.Caption := APPDOMAIN;
