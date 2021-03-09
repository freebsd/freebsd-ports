--- include/iprt/types.h.orig	2018-05-09 16:32:07 UTC
+++ include/iprt/types.h
@@ -56,22 +56,9 @@ RT_C_DECLS_END
 #  include <sys/types.h>
 
 # elif defined(RT_OS_FREEBSD) && defined(_KERNEL)
-    /*
-     * Kludge for the FreeBSD kernel:
-     *  stddef.h and sys/types.h have slightly different offsetof definitions
-     *  when compiling in kernel mode. This is just to make GCC shut up.
-     */
-#  ifndef _STDDEF_H_
-#   undef offsetof
-#  endif
+
 #  include <sys/stddef.h>
-#  ifndef _SYS_TYPES_H_
-#   undef offsetof
-#  endif
 #  include <sys/types.h>
-#  ifndef offsetof
-#   error "offsetof is not defined!"
-#  endif
 
 # elif defined(RT_OS_FREEBSD) && HC_ARCH_BITS == 64 && defined(RT_ARCH_X86)
     /*
