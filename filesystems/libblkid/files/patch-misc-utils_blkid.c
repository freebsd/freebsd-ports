--- misc-utils/blkid.c.orig	2025-06-24 07:55:28 UTC
+++ misc-utils/blkid.c
@@ -876,6 +876,7 @@ int main(int argc, char **argv)
 			else if (S_ISREG(sb.st_mode))
 				;
 			else if (S_ISCHR(sb.st_mode)) {
+#ifdef __linux__
 				char buf[PATH_MAX];
 
 				if (!sysfs_chrdev_devno_to_devname(
@@ -883,6 +884,7 @@ int main(int argc, char **argv)
 					continue;
 				if (strncmp(buf, "ubi", 3) != 0)
 					continue;
+#endif
 			} else
 				continue;
 
