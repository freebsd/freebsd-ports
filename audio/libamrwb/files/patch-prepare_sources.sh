--- prepare_sources.sh.orig	Thu Jun  7 00:29:29 2007
+++ prepare_sources.sh	Sun Jul 15 01:00:53 2007
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
@@ -24,7 +24,7 @@
 patch <amrwb-any-cflags.patch
 patch <amrwb-dhf-declaration.patch
 
-for FILE in {dec,enc}_if.{c,h} ; do
+for FILE in dec_if.[ch] enc_if.[ch] ; do
     echo "modifying file $FILE"
     if test $FILE = ${FILE%.h} ; then
 	ENDSTRING="^}"
@@ -47,3 +47,5 @@
     mv $FILE.new $FILE
     rm $FILE.def $FILE.all
 done
+
+trap 0
