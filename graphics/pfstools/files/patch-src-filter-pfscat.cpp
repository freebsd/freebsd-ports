--- src/filter/pfscat.cpp.orig	2008-01-01 13:01:21 UTC
+++ src/filter/pfscat.cpp
@@ -27,6 +27,7 @@
 #include <pfs.h>
 #include <climits>
 #include <iostream>
+#include <vector>
 #include <getopt.h>
 #include <fcntl.h>
 #include <stdlib.h>
@@ -202,16 +203,12 @@ if (alignment==UNSP) throw pfs::Exceptio
 
 pfs::FrameFileIterator it ( argc, argv, "rb", NULL, NULL, optString, cmdLineOptions);
 int pipe_no = 0;
-pfs::FrameFile * ff;
-ff = (pfs::FrameFile *) malloc ((pipe_no+1) * sizeof(pfs::FrameFile));
-
+std::vector<pfs::FrameFile> ff;
 while (1) {
-    ff[pipe_no] = it.getNextFrameFile();
+    ff.push_back(it.getNextFrameFile());
     if (ff[pipe_no].fh == NULL) break; // no more files
     pipe_no++;
-    ff=(pfs::FrameFile *) realloc(ff, (pipe_no+1)*sizeof(pfs::FrameFile));
     }
-    
 if(pipe_no == 0) { // no named pipes
     pipe_no = 1;
     pipes = false;
@@ -408,7 +405,6 @@ if(!pipes) {
     }
 
 for (int i=0; i<pipe_no; i++) it.closeFrameFile(ff[i]);
-free(ff);
 }
 
 
