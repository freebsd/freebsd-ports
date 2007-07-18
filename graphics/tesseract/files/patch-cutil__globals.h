--- ./cutil/globals.h.orig	2007-05-16 05:13:26.000000000 +0400
+++ ./cutil/globals.h	2007-07-18 15:54:41.000000000 +0400
@@ -45,9 +45,11 @@
 extern int debugs[MAXPROC];      /*debug flags */
 extern int plots[MAXPROC];       /*plot flags */
 extern int corners[4];           /*corners of scan window */
+extern "C" {
 extern int optind;               /*option index */
 extern char *optarg;             /*option argument */
                                  /*image file name */
+}
 extern char imagefile[FILENAMESIZE];
                                  /* main directory */
 extern char directory[FILENAMESIZE];
