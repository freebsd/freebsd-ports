--- src/misc.c.orig	Wed Jun 30 06:00:47 1999
+++ src/misc.c	Sat Mar 17 22:23:58 2001
@@ -394,7 +394,7 @@
      "  -a, --alltext           Print all text characters.\n"
      "  -b, --buffer            Buffer the entire file in memory.\n"
      "                            Much faster and enables insert/delete.\n"
-#if  defined (__linux__) || defined (__OpenBSD__)
+#if  defined (__linux__) || defined (__OpenBSD__) || defined(__FreeBSD__)
      "  -d, --disk              Edit a fixed disk, i.e. /dev/hda (Read-only)\n"
      "  -f, --force             Force editing of disk.\n"
      "                            Needed to write to disks.\n"
