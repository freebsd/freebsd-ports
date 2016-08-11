--- src/record_dialog.c.orig	1998-11-08 23:22:55 UTC
+++ src/record_dialog.c
@@ -524,7 +524,7 @@ Boolean update_record(XtPointer client_d
     sprintf(MD->mw->messages,"%.2lf kbytes (%.2lfs)",
 	    (double)playsize/1024,recordtime);
     XtVaSetValues(label5,XtNlabel, MD->mw->messages, NULL);
-#if defined(linux)||defined(FreeBSD)||defined(sun)
+#if defined(linux)||defined(__FreeBSD__)||defined(sun)
     usleep(80000);
 #elif defined(sgi)
     sginap(CLK_TCK/(ONE_SECOND/80000));
