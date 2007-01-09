--- molden.f~	Mon Jul 10 20:46:06 2006
+++ molden.f	Tue Jan  9 10:43:24 2007
@@ -255,7 +255,6 @@
       common /vrmlhl/ spcdfil
       common /pmflvl/ ipmfm,ipmfh,pmflev(mxpmfl),levcol(mxpmfl)
       common /comsrf/ vo(3), rt(3),v1t(3),v2t(3),v3t(3)
-      external iargc
       dimension fcnt(mxcntr)
       character title*80, keywrd*160, keyhlp*80, keyori*160
       character tmpstr*80,movfil*80,vrmlfil*80,povfil*80,oglfil*80
