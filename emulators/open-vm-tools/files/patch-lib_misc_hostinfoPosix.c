--- lib/misc/hostinfoPosix.c.orig	2017-07-28 21:59:15 UTC
+++ lib/misc/hostinfoPosix.c
@@ -1,5 +1,5 @@
 /*********************************************************
- * Copyright (C) 1998-2016 VMware, Inc. All rights reserved.
+ * Copyright (C) 1998-2017 VMware, Inc. All rights reserved.
  *
  * This program is free software; you can redistribute it and/or modify it
  * under the terms of the GNU Lesser General Public License as published
@@ -1080,28 +1080,32 @@ HostinfoOSData(void)
 
       Str_Strcpy(osName, distroShort, sizeof osName);
    } else if (strstr(osNameFull, "FreeBSD")) {
-      size_t nameLen = sizeof STR_OS_FREEBSD - 1;
-      size_t releaseLen = 0;
-      char *dashPtr;
+      char distroShort[DISTRO_BUF_SIZE];
+      int majorVersion;
 
       /*
-       * FreeBSD releases report their version as "x.y-RELEASE". We'll be
-       * naive look for the first dash, and use everything before it as the
-       * version number.
+       * FreeBSD releases report their version as "x.y-RELEASE".
        */
 
-      dashPtr = Str_Strchr(buf.release, '-');
-      if (dashPtr != NULL) {
-         releaseLen = dashPtr - buf.release;
+      majorVersion = Hostinfo_OSVersion(0);
+
+      /*
+       * FreeBSD 11 and later are identified using
+       * a different guestId.
+       */
+      if (majorVersion >= 11) {
+         Str_Strcpy(distroShort, STR_OS_FREEBSD11, sizeof distroShort);
+      } else {
+         Str_Strcpy(distroShort, STR_OS_FREEBSD, sizeof distroShort);
       }
 
-      if (nameLen + releaseLen + 1 > sizeof osName) {
+      if (strlen(distroShort) + 1 > sizeof osName) {
          Warning("%s: Error: buffer too small\n", __FUNCTION__);
 
          return FALSE;
       }
 
-      Str_Strcpy(osName, STR_OS_FREEBSD, sizeof osName);
+      Str_Strcpy(osName, distroShort, sizeof osName);
    } else if (strstr(osNameFull, "SunOS")) {
       size_t nameLen = sizeof STR_OS_SOLARIS - 1;
       size_t releaseLen = 0;
