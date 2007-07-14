--- prepare_sources.sh.orig	Wed Jun  6 23:52:12 2007
+++ prepare_sources.sh	Sat Jul 14 23:35:53 2007
@@ -1,10 +1,10 @@
-#! /bin/bash
+#! /bin/sh
 
 set -o errexit
-trap "rm -rf c-code *.c *.h readme.txt *.new *.def *.all" ERR
+trap "rm -rf c-code *.c *.h readme.txt *.new *.def *.all" 0
 
 if [ "$0" = prepare_sources.sh ] ; then
-    cd "$(if ! which 2>/dev/null prepare_sources.sh ; then echo . fi )"
+    cd "$(if ! which 2>/dev/null prepare_sources.sh ; then echo . ; fi )"
 else
     cd "${0%/*}"
 fi
@@ -23,7 +23,7 @@
 patch <amrnb-strict-aliasing.patch
 patch <amrnb-any-cflags.patch
 
-for FILE in interf_{dec,enc}.{c,h} ; do
+for FILE in interf_dec.[ch] interf_enc.[ch] ; do
     echo "modifying file $FILE"
     if test $FILE = ${FILE%.h} ; then
 	ENDSTRING="^}"
@@ -100,3 +100,5 @@
 	rm $FILE.def $FILE.all
     done
 done
+
+trap 0
