--- lib/wiper/wiperPosix.c	2008-07-02 00:31:18.000000000 +0200
+++ lib/wiper/wiperPosix.c	2008-07-08 10:22:47.000000000 +0200
@@ -36,9 +36,9 @@
 # include <sys/ucred.h>
 # include <sys/mount.h>
 # include <fstab.h>
-# if BSD_VERSION >= 50
+# if __FreeBSD_version >= 500000
 #  include <libgen.h>
-# endif /* BSD_VERSION < 50 */
+# endif /* __FreeBSD_version < 500000 */
 #endif
 #include <unistd.h>
 
@@ -210,7 +210,7 @@
     * function, as a whole, does not even apply to OS X, so this caveat is
     * only minor.
     */
-#if BSD_VERSION < 50
+#if __FreeBSD_version < 500000
    /*
     * Before FreeBSD 5, device nodes had static major/minor numbers.
     * (FreeBSD 5 included devfs which got rid of this concept.)  So
@@ -246,7 +246,7 @@
          retval = TRUE;
       }
    }
-#endif /* BSD_VERSION */
+#endif /* __FreeBSD_version */
 
    return retval;
 }
