--- slirc.c.orig	Tue Aug 24 00:15:11 1999
+++ slirc.c	Sat Jan  6 21:23:30 2001
@@ -8,6 +8,9 @@
 #include <signal.h>
 
 #include <slang.h>
+#ifdef KANJI
+#include <slkanji.h>
+#endif
 
 #include "slirc.h"
 
@@ -135,7 +138,16 @@
    char *cp,*pm;
    char stop, ch;
    
+#ifdef KANJI
+   char *KBuf;
+   int KSiz;
+   KSiz = strlen(cp0);
+   KBuf = kSLCodeConv(cp0, &KSiz, JIS, kSLcode, 1);
+   cp = strmcpy(RBuf, KBuf, sizeof(RBuf));
+   SLfree(KBuf);
+#else
    cp = strmcpy(RBuf, cp0, sizeof(RBuf));
+#endif
    /* now cp points to the terminating null in RBuf */
    while(1) {
       if (cp > RBuf && *(cp-1) == '\n') { /* back up past '\n' if is one. */
@@ -1031,6 +1043,10 @@
 	}
 	SLsmg_init_smg(); /* this does get_screen_size inside. */
 	SLang_set_abort_signal(NULL);
+#ifdef KANJI
+	kSLcode = EUC;
+	init_SLKanji();
+#endif
 	InitMainScreen();
 	SLang_VMessage_Hook = Local_vmessage;
 	SLang_Load_File_Hook = Local_SLang_load_file;
