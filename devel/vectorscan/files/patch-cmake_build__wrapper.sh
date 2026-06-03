--- cmake/build_wrapper.sh.orig	2025-10-30 04:35:01 UTC
+++ cmake/build_wrapper.sh
@@ -17,19 +17,19 @@ if [ `uname` = "FreeBSD" ]; then
 LIBC_SO=$("$@" --print-file-name=libc.so.6)
 NM_FLAG="-f"
 if [ `uname` = "FreeBSD" ]; then
-    # for freebsd, we will specify the name, 
+    # for freebsd, we will specify the name,
     # we will leave it work as is in linux
     LIBC_SO=/lib/libc.so.7
-    # also, in BSD, the nm flag -F corresponds to the -f flag in linux.
-    NM_FLAG="-F"
+    # FreeBSD nm uses -f with full format name, Linux -f uses single letters
+    NM_FLAG="-f posix"
 fi
 cp ${KEEPSYMS_IN} ${KEEPSYMS}
 # get all symbols from libc and turn them into patterns
-nm ${NM_FLAG} p -g -D ${LIBC_SO} | sed 's/\([^ @]*\).*/^\1$/' >> ${KEEPSYMS}
+nm ${NM_FLAG} -p -g -D ${LIBC_SO} | sed 's/\([^ @]*\).*/^\1$/' >> ${KEEPSYMS}
 # build the object
 "$@"
 # rename the symbols in the object
-nm ${NM_FLAG} p -g ${OUT} | cut -f1 -d' ' | grep -v -f ${KEEPSYMS} | sed -e "s/\(.*\)/\1\ ${PREFIX}_\1/" >> ${SYMSFILE}
+nm ${NM_FLAG} -p -g ${OUT} | cut -f1 -d' ' | grep -v -f ${KEEPSYMS} | sed -e "s/\(.*\)/\1\ ${PREFIX}_\1/" >> ${SYMSFILE}
 if test -s ${SYMSFILE}
 then
     objcopy --redefine-syms=${SYMSFILE} ${OUT}
