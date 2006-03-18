
$FreeBSD$

--- setup.sh.orig
+++ setup.sh
@@ -46,7 +46,7 @@
 
 DIALYZER_OTP_DIR=$1
 
-DIALYZER_DIR=`pwd`
+DIALYZER_DIR=${DIALYZER_OTP_DIR}/lib/dialyzer-${VSN}
 LN="ln -s"
 if (test `uname | grep -i cygwin`) ; then
     DIALYZER_DIR=`cygpath -m $DIALYZER_DIR`
