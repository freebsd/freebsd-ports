--- Documentation/Utilities/transform.sh.orig	Thu Jan 22 15:42:03 2004
+++ Documentation/Utilities/transform.sh	Thu Jan 22 15:42:08 2004
@@ -3,7 +3,7 @@
 # user-annotation capability.
 
 DIRS=$@
-EFED="perl Utilities/efed.pl"
+EFED="%%PERL%% Utilities/efed.pl"
 
 for d in $DIRS; do
   if test -d $d; then
