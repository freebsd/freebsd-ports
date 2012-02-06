--- ./newlib/libc/sys/psp/syscalls.c.orig	2012-01-25 19:33:12.000000000 +0000
+++ ./newlib/libc/sys/psp/syscalls.c	2012-01-25 19:33:12.000000000 +0000
@@ -0,0 +1,19 @@
+/*
+ * PSP Software Development Kit - http://www.pspdev.org
+ * -----------------------------------------------------------------------
+ * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
+ *
+ * syscalls.c - functions in systeam namespace goes here
+ *
+ * Copyright (c) 2007 Alper Akcan "anhanguera" <distchx@yahoo.com>
+ * 
+ */
+
+#include <stdio.h>
+
+int __psp_set_errno (int code);
+
+time_t _times (time_t *t)
+{
+       return __psp_set_errno(sceKernelLibcTime(t));
+} 
