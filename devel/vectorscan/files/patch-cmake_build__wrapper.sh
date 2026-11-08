--- cmake/build_wrapper.sh.orig	2026-08-23 08:41:50 UTC
+++ cmake/build_wrapper.sh
@@ -20,11 +20,7 @@ if [ `uname` = "FreeBSD" ]; then
 LIBC_SO=$("$@" --print-file-name=libc.so.6)
 NM_FLAG="-f"
 if [ `uname` = "FreeBSD" ]; then
-    # for freebsd, we will specify the name, 
-    # we will leave it work as is in linux
     LIBC_SO=/lib/libc.so.7
-    # also, in BSD, the nm flag -F corresponds to the -f flag in linux.
-    NM_FLAG="-F"
 fi
 cp ${KEEPSYMS_IN} ${KEEPSYMS}
 # get all symbols from libc and turn them into patterns
