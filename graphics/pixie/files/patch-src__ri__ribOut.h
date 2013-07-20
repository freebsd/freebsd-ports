--- src/ri/ribOut.h.orig
+++ src/ri/ribOut.h
@@ -237,7 +237,7 @@
 												const int	l	=	vsprintf(scratch,mes,args);
 
 												#ifdef HAVE_ZLIB
-													if (outputCompressed)	gzwrite(outFile,scratch,l);
+													if (outputCompressed)	gzwrite((gzFile)outFile,scratch,l);
 													else					fwrite(scratch,1,l,outFile);
 												#else
 													fwrite(scratch,1,l,outFile);
@@ -258,7 +258,7 @@
 												const int l	=	vsprintf(scratch,mes,args);
 
 												#ifdef HAVE_ZLIB
-													if (outputCompressed)	gzwrite(outFile,scratch,l);
+													if (outputCompressed)	gzwrite((gzFile)outFile,scratch,l);
 													else					fwrite(scratch,1,l,outFile);
 												#else
 													fwrite(scratch,1,l,outFile);
