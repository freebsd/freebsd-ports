--- src/misc.c.orig	Wed Jan 31 22:44:38 2001
+++ src/misc.c	Wed Jan 31 22:44:56 2001
@@ -394,7 +394,7 @@
      "  -a, --alltext           Print all text characters.\n"
      "  -b, --buffer            Buffer the entire file in memory.\n"
      "                            Much faster and enables insert/delete.\n"
-#if  defined (__linux__) || defined (__OpenBSD__)
+#if  defined (__linux__) || defined (__OpenBSD__) || defined(__FreeBSD__)
      "  -d, --disk              Edit a fixed disk, i.e. /dev/hda (Read-only)\n"
      "  -f, --force             Force editing of disk.\n"
      "                            Needed to write to disks.\n"
