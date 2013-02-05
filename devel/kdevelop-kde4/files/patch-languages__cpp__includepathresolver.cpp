--- ./languages/cpp/includepathresolver.cpp.orig	2012-08-01 12:42:36.000000000 -0700
+++ ./languages/cpp/includepathresolver.cpp	2012-09-26 18:24:36.912829509 -0700
@@ -198,7 +198,7 @@
         return "unsermake -k --no-real-compare -n " + makeParameters;
       } else {
         QString relativeFile = KUrl::relativePath(workingDirectory, absoluteFile);
-        return "make -k --no-print-directory -W \'" + absoluteFile + "\' -W \'" + relativeFile + "\' -n " + makeParameters;
+        return "gmake -k --no-print-directory -W \'" + absoluteFile + "\' -W \'" + relativeFile + "\' -n " + makeParameters;
       }
     }
 
