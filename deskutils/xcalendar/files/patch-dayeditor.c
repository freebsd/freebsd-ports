--- dayeditor.c.orig	Sun Oct  1 13:54:55 1995
+++ dayeditor.c	Mon Mar 12 20:55:07 2001
@@ -236,7 +236,7 @@
 {
     char           *getenv();
     DIR            *dirp;
-#if defined (SYSV) || defined(__osf__) || defined(SVR4)
+#if defined (SYSV) || defined(__osf__) || defined(SVR4) || defined(HAVE_DIRENT_H)
     struct dirent  *dp;
 #else
     struct direct  *dp;
@@ -1068,7 +1068,7 @@
         XawTextSetSource(editor->holiday,
 #ifdef XI18N
 			    (XtIsSubclass(old, multiSrcObjectClass) ?
-				 XtCreateWidget("holSource", asciiSrcObjectClass,
+				 XtCreateWidget("holSource", multiSrcObjectClass,
 								editor->holiday, args, n) :
 				 XtCreateWidget("holSource", asciiSrcObjectClass,
 								editor->holiday, args, n) ),
