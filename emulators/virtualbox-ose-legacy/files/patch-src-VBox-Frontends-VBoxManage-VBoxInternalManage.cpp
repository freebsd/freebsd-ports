--- src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp.orig	2010-12-01 18:09:24.000000000 +0100
+++ src/VBox/Frontends/VBoxManage/VBoxInternalManage.cpp	2011-03-16 10:58:37.000000000 +0100
@@ -178,8 +178,9 @@
                 "       (the partitioning information in the MBR file is ignored).\n"
                 "       The diskname is on Linux e.g. /dev/sda, and on Windows e.g.\n"
                 "       \\\\.\\PhysicalDrive0).\n"
-                "       On Linux host the parameter -relative causes a VMDK file to be created\n"
-                "       which refers to individual partitions instead to the entire disk.\n"
+                "       On Linux or FreeBSD host the parameter -relative causes a VMDK file to\n"
+                "       be created which refers to individual partitions instead to the entire\n"
+                "       disk.\n"
                 "       Optionally the created image can be immediately registered.\n"
                 "       The necessary partition numbers can be queried with\n"
                 "         VBoxManage internalcommands listpartitions\n"
@@ -926,12 +927,12 @@
         {
             fRegister = true;
         }
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
         else if (strcmp(argv[i], "-relative") == 0)
         {
             fRelative = true;
         }
-#endif /* RT_OS_LINUX */
+#endif /* RT_OS_LINUX || RT_OS_FREEBSD */
         else
         {
             return errorSyntax(USAGE_CREATERAWVMDK, "Invalid parameter '%s'", Utf8Str(argv[i]).raw());
@@ -1280,10 +1281,16 @@
             {
                 if (fRelative)
                 {
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
                     /* Refer to the correct partition and use offset 0. */
                     char *psz;
-                    vrc = RTStrAPrintf(&psz, "%s%u", rawdisk.raw(),
+                    vrc = RTStrAPrintf(&psz,
+#if defined(RT_OS_LINUX)
+                                       "%s%u",
+#elif defined(RT_OS_FREEBSD)
+                                       "%ss%u",
+#endif
+                                       rawdisk.raw(),
                                        partitions.aPartitions[i].uIndex);
                     if (RT_FAILURE(vrc))
                     {
