--- source/apphelpers.pas	2025-12-16 11:00:34.000000000 -0800
+++ source/apphelpers.pas	2025-12-17 00:09:19.625236000 -0800
@@ -1316,16 +1316,21 @@
   {$IFDEF LINUX}
   Result := '';
   {$ENDIF}
+  {$IFDEF FREEBSD}
+  Result := '';
+  {$ENDIF}
 end;
 
 function GetResourcesDir: String;
 begin
+  Result := GetAppDir;
   // point to resources dir in macOS app bundle
   {$IFDEF DARWIN}
   Result := GetAppDir + '..' + DirectorySeparator + 'Resources' + DirectorySeparator;
-  {$ELSE}
-  Result := GetAppDir;
   {$ENDIF}
+  {$IFDEF FREEBSD}
+  Result := '%%DATADIR%%/';
+  {$ENDIF}
 end;
 
 {**
@@ -2911,7 +2916,7 @@
   Output: String;
   CmdResult: Boolean;
 begin
-  {$IfDef LINUX}
+  {$if defined(LINUX) or defined(FREEBSD)}
   // Netcat on Linux
   CmdResult := Process.RunCommandInDir('', 'nc', ['-w 1 -zv 127.0.0.1 '+Port.ToString], Output);
   Result := not CmdResult;
@@ -3026,7 +3031,7 @@
     FreeLibrary(NTHandle);
   end;
   {$EndIf}
-  {$IfDef LINUX}
+  {$if defined(LINUX) or defined(FREEBSD)}
   IsWineStored := 0;
   {$EndIf}
   Result := IsWineStored = 1;
@@ -3063,6 +3068,9 @@
 function GetOS: String;
 begin
   Result := 'Unknown';
+  {$IfDef FreeBSD}
+  Result := 'FreeBSD';
+  {$EndIf}
   {$IfDef LINUX}
   Result := 'Linux';
   {$EndIf}
@@ -4569,7 +4577,7 @@
       1: begin // String
         Value := StringReplace(Value, CHR13REPLACEMENT, #13, [rfReplaceAll]);
         Value := StringReplace(Value, CHR10REPLACEMENT, #10, [rfReplaceAll]);
-        {$IfDef LINUX}
+        {$if defined(LINUX) or defined(FREEBSD)}
         Value := ConvertWindowsToLinuxPath(Value);
         {$EndIf}
         FRegistry.WriteString(Name, Value);
