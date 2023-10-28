--- compiler/globals.pas	2023-10-27 23:30:38.797736000 -0500
+++ compiler/globals.pas	2023-10-27 23:31:45.729414000 -0500
@@ -1023,6 +1023,19 @@
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
@@ -1062,6 +1075,9 @@
          Replace(s,'$OPENBSD_LOCALBASE',GetOpenBSDLocalBase);
          Replace(s,'$OPENBSD_X11BASE',GetOpenBSDX11Base);
 {$endif openbsd}
+{$ifdef freebsd}
+         Replace(s,'$FREEBSD_LOCALBASE',GetFreeBSDLocalBase);
+{$endif freebsd}
          if not substitute_env_variables then
            exit;
          { Replace environment variables between dollar signs }
