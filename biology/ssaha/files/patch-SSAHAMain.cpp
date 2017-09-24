--- ./Global/SSAHAMain.cpp.orig	2004-03-01 14:12:38.000000000 -0300
+++ ./Global/SSAHAMain.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -86,7 +86,8 @@
 Copyright (C) 2004 by Genome Research Limited\n\
 This software is released under the terms of version 2 of the GNU General\n\
 Public Licence, as published by the Free Software Foundation.\n\
-This is SSAHA Version 3.2, released 1st March 2004.\n\n";
+This is SSAHA Version 3.2, released 1st March 2004,\n\
+patched 26 January 2006.\n\n";
 
   Timer timeStamp;
 
@@ -623,7 +624,7 @@
     {
       pHashTable = new HashTablePacked( cerr, queryParams.saveName );
       if (    ( queryParams.wordLength <= 0 )
-	      || ( queryParams.wordLength*gBaseBits > ( 8*sizeof(Word)) -1 ) )
+	      || ( (size_t) queryParams.wordLength*gBaseBits > ( 8*sizeof(Word)) -1 ) )
       {
 	cerr << "Warning: word length (" << queryParams.wordLength 
 	     << ") outside valid range (0 to " 
@@ -656,7 +657,7 @@
       } // ~if
 
       if (    ( queryParams.wordLength <= 0 )
-	      || ( queryParams.wordLength*gResidueBits > ( 8*sizeof(Word)) -1 ) )
+	      || ( (size_t) queryParams.wordLength*gResidueBits > ( 8*sizeof(Word)) -1 ) )
       {
 	cerr << "Warning: word length (" << queryParams.wordLength 
 	     << ") outside valid range (0 to " 
@@ -782,7 +783,7 @@
   cerr << "Info: would expect " << expectedNumHits 
          << " hits per word for a random database of this size." << endl;
 
-  queryParams.maxStore=1+(int)(expectedNumHits*queryParams.maxStore);
+  queryParams.maxStore=(int)(expectedNumHits*queryParams.maxStore);
 
   cerr << "Info: will ignore hits on words that occur more than " 
        << queryParams.maxStore << " times in the database." << endl;
@@ -964,7 +965,7 @@ delete pQueryMode;
 
     } // ~else
 
-    assert( pAligner!=false);
+    assert(pAligner!=NULL);
 
     // ownership of *pAligner passes to *pPrintTask
     pPrintTask = new MatchTaskAlign( *pQuery, *pSubjectSource, pAligner,
@@ -1151,7 +1152,7 @@
     } // ~if
     dirent* dirEntry;
     string entryName;
-    while( dirEntry = readdir(pDir) )
+    while( 0 != ( dirEntry = readdir(pDir) ) )
     {
       entryName = (string) dirEntry->d_name;
       if ((entryName == ".")||(entryName=="..")) continue;
