--- compiler/globals.pas	2024-09-11 20:40:10.000000000 +0000
+++ compiler/globals.pas	2024-09-13 07:28:37.270196000 +0000
@@ -1042,6 +1042,19 @@
            FreeEnvPChar(envvalue);
          end;
 {$endif openbsd}
+{$ifdef freebsd}
+       function GetFreeBSDLocalBase: ansistring;
+         var
+           envvalue: pchar;
+         begin
+           envvalue := GetEnvPChar('LOCALBASE');
+           if assigned(envvalue) then
+             Result:=envvalue
+           else
+             Result:='/usr/local';
+           FreeEnvPChar(envvalue);
+         end;
+{$endif freebsd}
        var
          envstr: string;
          envvalue: pchar;
@@ -1081,6 +1094,9 @@
          Replace(s,'$OPENBSD_LOCALBASE',GetOpenBSDLocalBase);
          Replace(s,'$OPENBSD_X11BASE',GetOpenBSDX11Base);
 {$endif openbsd}
+{$ifdef freebsd}
+         Replace(s,'$FREEBSD_LOCALBASE',GetFreeBSDLocalBase);
+{$endif freebsd}
 {$ifdef xtensa}
          if idf_version > 0 then
            Replace(s,'$IDF_VERSION',idfversionstring(idf_version));
