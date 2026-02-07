Use BSD instead of GNU sed(1) convention
--- rules.mak.orig	2025-07-30 06:00:02 UTC
+++ rules.mak
@@ -17,7 +17,7 @@ ${DEPEND_FILE}: ${DEPSRCS}
 # it indicates a missing dependency somewhere in a upstream/parent Makefile.
 ${DEPEND_FILE}: ${DEPSRCS}
 	${CC} ${CFLAGS} ${CPPFLAGS} ${DFLAGS} ${DEPEND_FLAG} ${DEPSRCS} > ${DEPEND_FILE}$$PPID.tmp
-	${SED} -e "/#/D" -e "/ \//s/ \/.*\.h//" -e "/  \\\/D" -i ${DEPEND_FILE}$$PPID.tmp
+	${SED} -e "/#/D" -e "/ \//s/ \/.*\.h//" -e "/  \\\/D" -i '' ${DEPEND_FILE}$$PPID.tmp
 	${MV} -f ${DEPEND_FILE}$$PPID.tmp ${DEPEND_FILE}
 
 # Original Depend file generating line:
