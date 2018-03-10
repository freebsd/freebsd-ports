--- lib/auth/authPosix.c.orig	2017-12-15 21:11:49 UTC
+++ lib/auth/authPosix.c
@@ -1,5 +1,5 @@
 /*********************************************************
- * Copyright (C) 2003-2017 VMware, Inc. All rights reserved.
+ * Copyright (C) 2003-2018 VMware, Inc. All rights reserved.
  *
  * This program is free software; you can redistribute it and/or modify it
  * under the terms of the GNU Lesser General Public License as published
@@ -19,6 +19,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <errno.h>
 #include <unistd.h> // for access, crypt, etc.
 #if !defined USE_PAM && !defined __APPLE__
 #include <shadow.h>
@@ -262,8 +263,8 @@ static struct pam_conv PAM_conversation = {
 static AuthTokenInternal *
 AuthAllocateToken(void)
 {
+   long bufSize;
    AuthTokenInternal *ati;
-   size_t bufSize;
 
    /*
     * We need to get the maximum size buffer needed by getpwuid_r from
@@ -271,9 +272,15 @@ AuthAllocateToken(void)
     * by the Posix_Get*_r() wrappers.
     */
 
-   bufSize = (size_t) sysconf(_SC_GETPW_R_SIZE_MAX) * 4;
+   errno = 0;
+   bufSize = sysconf(_SC_GETPW_R_SIZE_MAX);
+   if ((errno != 0) || (bufSize <= 0)) {
+      bufSize = 16 * 1024;  // Unlimited; pick something reasonable
+   }
 
-   ati = Util_SafeMalloc(sizeof *ati + bufSize);
+   bufSize *= 4;
+
+   ati = Util_SafeMalloc(sizeof *ati + (size_t) bufSize);
    ati->bufSize = bufSize;
 
    return ati;
