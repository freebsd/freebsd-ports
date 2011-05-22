--- src/VBox/HostDrivers/Support/SUPR3HardenedVerify.cpp.orig	2011-05-16 18:33:40.000000000 +0200
+++ src/VBox/HostDrivers/Support/SUPR3HardenedVerify.cpp	2011-05-19 16:53:54.000000000 +0200
@@ -1187,6 +1187,11 @@
            permit grand parents and beyond to be group writable by admin. */
         if (pFsObjState->Stat.st_gid != 80 /*admin*/) /** @todo dynamically resolve the admin group? */
 #endif
+#ifdef RT_OS_FREEBSD
+        /* PC-BSD 9 has group-writable application directory, similar to OSX and
+           their Applications directory */
+        if (pFsObjState->Stat.st_gid != 5 /*operators*/) /* Allow operators group-writes */
+#endif
             return supR3HardenedSetError3(VERR_SUPLIB_WRITE_NON_SYS_GROUP, pErrInfo,
                                           "The group is not a system group and it has write access to '", pszPath, "'");
     }
