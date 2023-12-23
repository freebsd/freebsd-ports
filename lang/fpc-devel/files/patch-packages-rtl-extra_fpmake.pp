--- packages/rtl-extra/fpmake.pp	2023-10-27 17:59:48.000000000 -0500
+++ packages/rtl-extra/fpmake.pp	2023-12-22 18:28:44.664770000 -0500
@@ -20,7 +20,7 @@
 //  IPCcdeclOSes  = [Darwin,iphonesim,ios];
 
   PrinterOSes   = [go32v2,msdos,os2,win32,win64,atari]+unixlikes-[beos,haiku,morphos];
-  SerialOSes    = [android,linux,netbsd,openbsd,win32,win64];
+  SerialOSes    = [android,linux,freebsd,netbsd,openbsd,win32,win64];
   UComplexOSes  = [atari,embedded,emx,gba,go32v2,msdos,nativent,nds,netware,netwlibc,os2,sinclairql,symbian,watcom,wii,wince,win32,win64,freertos,wasi]+UnixLikes+AllAmigaLikeOSes;
   MatrixOSes    = [atari,embedded,emx,gba,go32v2,msdos,nativent,nds,netware,netwlibc,os2,sinclairql,symbian,watcom,wii,win32,win64,wince,freertos,wasi]+UnixLikes+AllAmigaLikeOSes;
   ObjectsOSes   = [atari,embedded,emx,gba,go32v2,macosclassic,msdos,nds,netware,netwlibc,os2,sinclairql,symbian,watcom,wii,win16,win32,win64,wince,freertos,wasi]+UnixLikes+AllAmigaLikeOSes;
