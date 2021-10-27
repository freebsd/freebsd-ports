--- src/main.cpp.orig	2021-10-19 02:19:29 UTC
+++ src/main.cpp
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <sysexits.h>
 #include "fastqreader.h"
 #include "unittest.h"
 #include <time.h>
@@ -18,7 +19,7 @@ int main(int argc, char* argv[]){
     if(argc == 1) {
         cerr << "fastp: an ultra-fast all-in-one FASTQ preprocessor" << endl << "version " << FASTP_VER << endl;
         //cerr << "fastp --help to see the help"<<endl;
-        //return 0;
+        return EX_USAGE;
     }
     if (argc == 2 && strcmp(argv[1], "test")==0){
         UnitTest tester;
