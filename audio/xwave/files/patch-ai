--- src/record_dialog.c.orig	Mon Nov  9 08:22:55 1998
+++ src/record_dialog.c	Fri Jun 30 19:49:18 2000
@@ -524,7 +524,7 @@
     sprintf(MD->mw->messages,"%.2lf kbytes (%.2lfs)",
 	    (double)playsize/1024,recordtime);
     XtVaSetValues(label5,XtNlabel, MD->mw->messages, NULL);
-#if defined(linux)||defined(FreeBSD)||defined(sun)
+#if defined(linux)||defined(__FreeBSD__)||defined(sun)
     usleep(80000);
 #elif defined(sgi)
     sginap(CLK_TCK/(ONE_SECOND/80000));
