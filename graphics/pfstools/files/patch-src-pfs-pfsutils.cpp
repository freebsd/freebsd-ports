--- src/pfs/pfsutils.cpp.orig	2006-09-21 21:42:54.000000000 +0000
+++ src/pfs/pfsutils.cpp	2014-02-20 19:04:01.566588122 +0000
@@ -81,7 +81,7 @@
   char fileName[1024];
   FILE *stdinout;
 
-  typedef list<FilePattern> PatternList;
+  typedef std::list<FilePattern> PatternList;
 
   PatternList patternList;
   PatternList::iterator currentPattern;
