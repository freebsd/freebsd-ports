--- ../sal/osl/unx/file.c.orig	Thu Oct  4 15:09:21 2001
+++ ../sal/osl/unx/file.c
@@ -123,11 +123,16 @@
 #include <ctype.h>
 static const sal_Char* MOUNTTAB="/etc/mtab";
 
-#elif defined(NETBSD)
+#elif defined(NETBSD) || defined(FREEBSD)
+#include <sys/param.h>
+#include <sys/ucred.h>
 #include <sys/mount.h>
 #include <ufs/ufs/quota.h>
 #include <ctype.h>
-static const sal_Char* MOUNTTAB="/etc/mtab"; 
+#define  HAVE_STATFS_H
+/* No mounting table on *BSD
+ * This information is stored only in the kernel. */
+/* static const sal_Char* MOUNTTAB="/etc/mtab"; */
 
 #elif defined(IRIX)
 #include <mntent.h>
@@ -137,7 +142,7 @@
 #include <ctype.h>
 static const sal_Char* MOUNTTAB="/etc/mtab";
 
-#elif defined(MACOSX) || defined(FREEBSD)
+#elif defined(MACOSX) 
 #include <ufs/ufs/quota.h>
 #include <ctype.h>
 static const sal_Char* MOUNTTAB="/etc/mtab";
@@ -4224,10 +4229,20 @@
     mntfile = fopen(MOUNTTAB,"r");
 #endif /* SOLARIS */
 
+#if defined(NETBSD) || defined(FREEBSD)
+    struct statfs *mntbufp;
+    int mntentries,i;
+    mntentries = getmntinfo(&mntbufp,MNT_WAIT);
 
     buffer[0] = '\0';
     
+    if(mntentries == 0)
+#else    
+
+    buffer[0] = '\0';
+
     if ( mntfile == 0 )
+#endif
     {
         nRet=errno;
 #ifdef DEBUG_OSL_FILE
@@ -4286,7 +4301,21 @@
     }
 #endif /* SOLARIS */
 
+#if defined(NETBSD) || defined(FREEBSD)
+    i=0;
+    while ( i < mntentries )
+    {
+       if ( strcmp(mntbufp[i].f_mntonname,buffer) == 0 )
+       {
+           *bMountPoint=sal_True;
+           return osl_File_E_None;
+       }
+       i++;
+    }
+#endif
+#if ! ( defined(NETBSD) || defined(FREEBSD) )
     fclose(mntfile);
+#endif
     *bMountPoint=sal_False;
     return osl_File_E_None;
 }
