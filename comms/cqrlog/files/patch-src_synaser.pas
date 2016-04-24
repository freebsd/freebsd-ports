--- src/synaser.pas.orig	2016-04-20 16:06:15 UTC
+++ src/synaser.pas
@@ -302,7 +302,7 @@ type
     procedure DcbToTermios(const dcb: TDCB; var term: termios); virtual;
     procedure TermiosToDcb(const term: termios; var dcb: TDCB); virtual;
 {$ENDIF}
-{$IFDEF LINUX}
+{$IFDEF UNIX}
     function ReadLockfile: integer; virtual;
     function LockfileName: String; virtual;
     procedure CreateLockfile(PidNr: integer); virtual;
@@ -591,7 +591,7 @@ type
 
     {:Raise Synaser error with ErrNumber code. Usually used by internal routines.}
     procedure RaiseSynaError(ErrNumber: integer); virtual;
-{$IFDEF LINUX}
+{$IFDEF UNIX}
     function  cpomComportAccessible: boolean; virtual;{HGJ}
     procedure cpomReleaseComport; virtual; {HGJ}
 {$ENDIF}
@@ -766,7 +766,7 @@ begin
   end;
   if InstanceActive then
   begin
-    {$IFDEF LINUX}
+    {$IFDEF UNIX}
     if FLinuxLock then
       cpomReleaseComport;
     {$ENDIF}
@@ -917,7 +917,7 @@ begin
   FHandle := THandle(fpOpen(FDevice, O_RDWR or O_SYNC));
 {$ENDIF}
   SerialCheck(integer(FHandle));
-  {$IFDEF LINUX}
+  {$IFDEF UNIX}
   if FLastError <> sOK then
     if FLinuxLock then
       cpomReleaseComport;
@@ -949,7 +949,7 @@ begin
   begin
     SetSynaError(ErrNoDeviceAnswer);
     FileClose(integer(FHandle));         {HGJ}
-    {$IFDEF LINUX}
+    {$IFDEF UNIX}
     if FLinuxLock then
       cpomReleaseComport;                {HGJ}
     {$ENDIF}                             {HGJ}
@@ -1899,7 +1899,7 @@ begin
   {$IFNDEF FPC}
   SerialCheck(ioctl(integer(FHandle), TCFLSH, TCIOFLUSH));
   {$ELSE}
-  SerialCheck(fpioctl(integer(FHandle), TCFLSH, Pointer(PtrInt(TCIOFLUSH))));
+  SerialCheck(TCFlush(integer(FHandle), TCIOFLUSH));
   //SerialCheck(fpioctl(integer(FHandle), TCFLSH, TCIOFLUSH));
   {$ENDIF}
   FBuffer := '';
@@ -2136,7 +2136,7 @@ end;
   Ownership Manager.
 }
 
-{$IFDEF LINUX}
+{$IFDEF UNIX}
 
 function TBlockSerial.LockfileName: String;
 var
