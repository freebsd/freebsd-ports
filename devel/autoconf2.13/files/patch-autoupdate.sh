--- autoupdate.sh.orig	2000-02-27 16:18:10 UTC
+++ autoupdate.sh
@@ -26,7 +26,7 @@ Usage: autoupdate [-h] [--help] [-m dir] [--macrodir=d
 Usage: autoupdate [-h] [--help] [-m dir] [--macrodir=dir] 
        [--version] [template-file]" 
 
-sedtmp=/tmp/acups.$$
+sedtmp=`mktemp ${TMPDIR-/tmp}/acups.XXXXXXXXXX` || exit 1
 # For debugging.
 #sedtmp=/tmp/acups
 show_version=no
@@ -66,7 +66,7 @@ fi
 
 : ${SIMPLE_BACKUP_SUFFIX='~'}
 
-tmpout=acupo.$$
+tmpout=`mktemp acupo.XXXXXXXXXX` || { rm -f $sedtmp; exit 1; }
 trap 'rm -f $sedtmp $tmpout; exit 1' 1 2 15
 case $# in
   0) infile=configure.in; out="> $tmpout"
