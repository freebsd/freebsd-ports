--- acinclude.m4.orig	Fri Mar 17 16:32:15 2000
+++ acinclude.m4	Fri Mar 16 17:28:37 2001
@@ -414,6 +414,10 @@
 	    DXEXEC_EXP='-Wl,-export-dynamic'
 	    AC_DEFINE_UNQUOTED(DXEXEC_EXP, $DXEXEC_EXP)
 	    ;;
+	freebsd)
+	    DXEXEC_EXP='-Wl,-export-dynamic'
+	    AC_DEFINE_UNQUOTED(DXEXEC_EXP, $DXEXEC_EXP)
+	    ;;
     esac
     AC_MSG_RESULT(done)
 ])
@@ -705,7 +709,7 @@
 AC_CACHE_VAL(ac_cv_type_$1,
 [AC_EGREP_CPP(dnl
 changequote(<<,>>)dnl
-<<$1[^a-zA-Z_0-9]>>dnl
+<<typedef.*[^a-zA-Z_0-9]$1[\\t ]*;>>dnl
 changequote([,]), [#include <sys/types.h>
 #if STDC_HEADERS
 #include <stdlib.h>
