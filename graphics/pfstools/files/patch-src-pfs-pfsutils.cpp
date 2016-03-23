--- src/pfs/pfsutils.cpp.orig	2006-09-21 21:42:54 UTC
+++ src/pfs/pfsutils.cpp
@@ -81,7 +81,7 @@ class FrameFileIteratorImpl
   char fileName[1024];
   FILE *stdinout;
 
-  typedef list<FilePattern> PatternList;
+  typedef std::list<FilePattern> PatternList;
 
   PatternList patternList;
   PatternList::iterator currentPattern;
