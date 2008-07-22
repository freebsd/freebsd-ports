--- send-pr/install-sid.sh.orig	2008-07-22 12:35:01.000000000 +0300
+++ send-pr/install-sid.sh	2008-07-22 12:35:11.000000000 +0300
@@ -27,7 +27,7 @@
 sysconfdir="@sysconfdir@"
 
 COMMAND=`echo $0 | sed -e 's,.*/,,g'`
-function usage() {
+usage() {
 	cat << __EOF__ >&2
 Usage: $COMMAND [OPTIONS] submitter-id
 
