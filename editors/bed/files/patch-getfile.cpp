--- src/getfile.cpp.orig	Thu Apr 17 06:53:47 2003
+++ src/getfile.cpp	Mon Dec  8 10:33:51 2003
@@ -503,8 +503,8 @@
 		};
 #include "varmacro.h"
 #ifdef OLDGCCVARMACRO
-#define	keydef(sym,keys...) input.putseq(sym,sizeof((unsigned char [])##keys),(unsigned char []) ##keys)  VARMACRO
-#define	seqput(sym,keys...) keyinp->putseq(sym,sizeof((unsigned char [])##keys),(unsigned char []) ##keys) VARMACRO
+#define	keydef(sym,keys...) input.putseq(sym,sizeof((unsigned char [])keys),(unsigned char []) keys)  VARMACRO
+#define	seqput(sym,keys...) keyinp->putseq(sym,sizeof((unsigned char [])keys),(unsigned char []) keys) VARMACRO
 #else
 #define	keydef(sym,...) input.putseq(sym,sizeof((unsigned char [])__VA_ARGS__),(unsigned char []) __VA_ARGS__)  
 #define	seqput(sym,...) keyinp->putseq(sym,sizeof((unsigned char [])__VA_ARGS__),(unsigned char []) __VA_ARGS__) 
