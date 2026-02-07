--- compiler/globals.pas	2020-10-03 17:51:53.151305000 -0500
+++ compiler/globals.pas	2020-10-03 17:53:05.954948000 -0500
@@ -897,6 +897,19 @@
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
@@ -933,6 +946,9 @@
          Replace(s,'$OPENBSD_LOCALBASE',GetOpenBSDLocalBase);
          Replace(s,'$OPENBSD_X11BASE',GetOpenBSDX11Base);
 {$endif openbsd}
+{$ifdef freebsd}
+         Replace(s,'$FREEBSD_LOCALBASE',GetFreeBSDLocalBase);
+{$endif freebsd}
          { Replace environment variables between dollar signs }
          i := pos('$',s);
          while i>0 do
