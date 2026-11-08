--- packages/rtl-extra/fpmake.pp	2025-04-09 13:36:23.000000000 -0700
+++ packages/rtl-extra/fpmake.pp	2025-04-09 19:49:01.544063000 -0700
@@ -20,7 +20,7 @@
 //  IPCcdeclOSes  = [Darwin,iphonesim,ios];
 
   PrinterOSes   = [go32v2,msdos,os2,win32,win64,atari]+unixlikes-[beos,haiku,morphos];
-  SerialOSes    = [android,linux,netbsd,openbsd,win32,win64];
+  SerialOSes    = [android,freebsd,linux,netbsd,openbsd,win32,win64];
   UComplexOSes  = [atari,embedded,emx,gba,go32v2,msdos,nativent,nds,netware,netwlibc,os2,sinclairql,human68k,symbian,watcom,wii,wince,win32,win64,freertos,wasip1,wasip1threads]+UnixLikes+AllAmigaLikeOSes;
   MatrixOSes    = [atari,embedded,emx,gba,go32v2,msdos,nativent,nds,netware,netwlibc,os2,sinclairql,human68k,symbian,watcom,wii,win32,win64,wince,freertos,wasip1,wasip1threads]+UnixLikes+AllAmigaLikeOSes;
   ObjectsOSes   = [atari,embedded,emx,gba,go32v2,macosclassic,msdos,nds,netware,netwlibc,os2,sinclairql,human68k,symbian,watcom,wii,win16,win32,win64,wince,freertos,wasip1,wasip1threads]+UnixLikes+AllAmigaLikeOSes;
