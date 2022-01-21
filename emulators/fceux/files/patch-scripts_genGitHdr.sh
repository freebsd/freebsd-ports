--- scripts/genGitHdr.sh.orig	2022-01-17 18:50:37 UTC
+++ scripts/genGitHdr.sh
@@ -3,12 +3,13 @@
 OUTPUT_DIR=$1;
 
 FILE="fceux_git_info.cpp"
-TMP_FILE="/tmp/$FILE";
+TMP_FILE="`mktemp /tmp/$FILE.XXXXXX`";
 
 echo "Output File: $OUTPUT_DIR/$FILE";
 
-GIT_URL=`git config --get remote.origin.url`;
-GIT_REV=`git rev-parse HEAD`;
+# print useful information in lieu of a git revision we don't have
+GIT_URL="FreeBSD Ports Collection";
+GIT_REV="%%PKGNAME%%";
 
 echo "// fceux_git_info.cpp -- DO NOT EDIT: This file is auto-generated at build" >| $TMP_FILE;
 echo "#include \"Qt/fceux_git_info.h\" " >> $TMP_FILE;
