--- ./src/VBox/Runtime/r3/freebsd/RTSystemQueryTotalRam-freebsd.cpp.ORIG	2013-06-30 09:27:59.000000000 +0200
+++ ./src/VBox/Runtime/r3/freebsd/RTSystemQueryTotalRam-freebsd.cpp	2013-06-30 09:51:29.000000000 +0200
@@ -0,0 +1,80 @@
+/* $Id: RTSystemQueryTotalRam-freebsd.cpp $ */
+/** @file
+ * IPRT - RTSystemQueryTotalRam, FreeBSD style
+ */
+
+/*
+ * Copyright (C) 2013 Martin Birgmeier, Oracle Corporation
+ *
+ * This file is part of VirtualBox Open Source Edition (OSE), as
+ * available from http://www.virtualbox.org. This file is free software;
+ * you can redistribute it and/or modify it under the terms of the GNU
+ * General Public License (GPL) as published by the Free Software
+ * Foundation, in version 2 as it comes in the "COPYING" file of the
+ * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+ * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+ *
+ * The contents of this file may alternatively be used under the terms
+ * of the Common Development and Distribution License Version 1.0
+ * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
+ * VirtualBox OSE distribution, in which case the provisions of the
+ * CDDL are applicable instead of those of the GPL.
+ *
+ * You may elect to license modified versions of this file under the
+ * terms and conditions of either the GPL or the CDDL or both.
+ */
+
+
+/*******************************************************************************
+*   Header Files                                                               *
+*******************************************************************************/
+#include <iprt/system.h>
+#include "internal/iprt.h"
+
+#include <iprt/err.h>
+#include <iprt/assert.h>
+#include <iprt/string.h>
+
+/* FreeBSD */
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/errno.h>
+
+RTDECL(int) RTSystemQueryTotalRam(uint64_t *pcb)
+{
+    int mib[2];
+    size_t pcblen = sizeof(*pcb);
+
+    AssertPtrReturn(pcb, VERR_INVALID_POINTER);
+
+    mib[0] = CTL_HW;
+    mib[1] = HW_PHYSMEM;	/* HW_REALMEM is also possible, but
+				   includes non-main memory as well */
+    *pcb = 0;
+    if (sysctl(mib, 2, pcb, &pcblen, NULL, 0) == 0) {
+	if (pcblen == sizeof(*pcb))
+	    return VINF_SUCCESS;
+	else
+	    return VERR_NO_MEMORY;	/* XXX */
+    }
+    return RTErrConvertFromErrno(errno);
+}
+
+RTDECL(int) RTSystemQueryAvailableRam(uint64_t *pcb)
+{
+    int mib[2];
+    size_t pcblen = sizeof(*pcb);
+
+    AssertPtrReturn(pcb, VERR_INVALID_POINTER);
+
+    mib[0] = CTL_HW;
+    mib[1] = HW_USERMEM;
+    *pcb = 0;
+    if (sysctl(mib, 2, pcb, &pcblen, NULL, 0) == 0) {
+	if (pcblen == sizeof(*pcb))
+	    return VINF_SUCCESS;
+	else
+	    return VERR_NO_MEMORY;	/* XXX */
+    }
+    return RTErrConvertFromErrno(errno);
+}
