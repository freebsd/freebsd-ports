--- newlib/libc/sys/psp/syscalls.c.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/syscalls.c	2007-06-01 12:22:26.000000000 +0300
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
