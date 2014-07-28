--- filehandling.c.orig	Tue Feb 15 03:03:56 2000
+++ filehandling.c	Mon Jun 12 19:07:56 2000
@@ -458,13 +458,18 @@
   FILE *theFile;
   int c;
   char *desc = NULL;
+  int fd;
   
   theRealFileName = PLGetString(PLGetFilename(pl));
   if(!theRealFileName) return NO;
   
   if (atomically)
     {
+#ifndef HAVE_MKSTEMP
       theFileName = tmpnam(NULL);
+#else
+      theFileName = "/var/tmp/tmp.XXXXXX";
+#endif
       strcpy(tmp_fileName, theFileName);
 
       if((tmp_basename=strtok(tmp_fileName, "/")))
@@ -492,14 +497,31 @@
 	} 
       
       theFileName = strcat(dirname, basename);
+#ifdef HAVE_MKSTEMP
+      strcpy(tmp_fileName, theFileName);
+      if ((fd = mkstemp(tmp_fileName)) == -1)
+
+        goto failure; /* Not reached */
+
+      if ((theFile = fdopen(fd, "w+")) == NULL)
+
+        goto failure; /* Not reached */
+
+      theFileName = tmp_fileName;
+#endif
     } 
   else
     { 
       theFileName = theRealFileName;
+#ifdef HAVE_MKSTEMP
+      theFile = fopen(theFileName, "w");
+#endif /* HAVE_MKSTEMP */
     } 
 
   /* Open the file (whether temp or real) for writing. */
+#ifndef HAVE_MKSTEMP
   theFile = fopen(theFileName, "w");
+#endif /* ! HAVE_MKSTEMP */
 
   if (theFile == NULL)          /* Something went wrong; we weren't
                                  * even able to open the file. */
