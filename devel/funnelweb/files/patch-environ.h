--- environ.h.orig	1999-05-16 01:09:55.000000000 +0200
+++ environ.h
@@ -84,6 +84,7 @@ Changes:
 #define    OS_L86 0  /*    Linux         */
 #define    OS_AIX 0  /*    AIX           */
 #define    OS_FBD 0  /*    FreeBSD       */
+#define    OS_DFB 0  /*    DragonFly     */
 
 
 #ifdef  THINK_C      
@@ -212,6 +213,13 @@ Changes:
 #define  OS_FBD  1
 #endif
 
+#ifdef  __DragonFly__
+#undef  OS_UNX 
+#define  OS_UNX  1
+#undef  OS_DFB 
+#define  OS_DFB  1
+#endif
+
 #if (OS_MAC + OS_UNX + OS_VMS + OS_DOS + OS_W32) == 0
    #error Error: No operating system class has been selected.
 #endif
@@ -222,7 +230,7 @@ Changes:
 
 #if OS_UNX
 #define OS_UNXSUM1 (OS_HPU+OS_OSF+OS_SUN+OS_SOL+OS_ULT)
-#define OS_UNXSUM2 (OS_IRX+OS_B86+OS_L86+OS_AIX+OS_FBD)
+#define OS_UNXSUM2 (OS_IRX+OS_B86+OS_L86+OS_AIX+OS_FBD+OS_DFB)
 #if ((OS_UNXSUM1+OS_UNXSUM2) != 1)
    #error Error: Exactly one Unix operating system must be chosen.
 #endif
