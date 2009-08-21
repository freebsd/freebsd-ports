--- newlib/libc/sys/psp/fdman.c.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/fdman.c	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,115 @@
+/*
+ * PSP Software Development Kit - http://www.pspdev.org
+ * -----------------------------------------------------------------------
+ * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
+ *
+ * fdman.c - File descriptor management.
+ *
+ * Copyright (c) 2006 Rafael Cabezas <rafpsp@gmail.com>
+ */
+#include <psptypes.h>
+#include <errno.h>
+#include "fdman.h"
+
+extern int  pspDisableInterrupts();
+extern void pspEnableInterrupts(int); 
+
+static __psp_descriptormap_type  __psp_descriptor_data_pool[__PSP_FILENO_MAX];
+__psp_descriptormap_type        *__psp_descriptormap       [__PSP_FILENO_MAX];
+
+void __psp_fdman_init()
+{
+	int scefd;
+
+	/* Initialize descriptor data*/
+	memset(__psp_descriptor_data_pool, 0, sizeof(__psp_descriptormap_type) *__PSP_FILENO_MAX);
+	/* Initialize descriptor map*/
+	memset(__psp_descriptormap,        0, sizeof(__psp_descriptormap_type*)*__PSP_FILENO_MAX);
+
+	scefd = sceKernelStdin();
+	if ((scefd >= 0) && (scefd < __PSP_FILENO_MAX)) {
+		__psp_descriptormap[0] = &__psp_descriptor_data_pool[0];
+		__psp_descriptormap[0]->sce_descriptor = scefd;
+		__psp_descriptormap[0]->type = __PSP_DESCRIPTOR_TYPE_TTY;
+	}
+	scefd = sceKernelStdout();
+	if ((scefd >= 0) && (scefd < __PSP_FILENO_MAX)) {
+		__psp_descriptormap[1] = &__psp_descriptor_data_pool[1];
+		__psp_descriptormap[1]->sce_descriptor = scefd;
+		__psp_descriptormap[1]->type = __PSP_DESCRIPTOR_TYPE_TTY;
+	}
+	scefd = sceKernelStderr();
+	if ((scefd >= 0) && (scefd < __PSP_FILENO_MAX)) {
+		__psp_descriptormap[2] = &__psp_descriptor_data_pool[2];
+		__psp_descriptormap[2]->sce_descriptor = scefd;
+		__psp_descriptormap[2]->type = __PSP_DESCRIPTOR_TYPE_TTY;
+	}
+}
+
+int __psp_fdman_get_new_descriptor()
+{
+	int i = 0;
+	int inten;
+
+	inten = pspDisableInterrupts(); /* lock here to make thread safe */
+	for (i = 0; i < __PSP_FILENO_MAX; i++) {
+		if (__psp_descriptormap[i] == NULL) {
+			__psp_descriptormap[i] = &__psp_descriptor_data_pool[i];
+			__psp_descriptormap[i]->ref_count++;
+			pspEnableInterrupts(inten); /* release lock */
+			return i;
+		}
+	}
+	pspEnableInterrupts(inten); /* release lock */
+		
+	errno = ENOMEM;
+	return -1;
+}
+
+int __psp_fdman_get_dup_descriptor(int fd)
+{
+	int i = 0;
+	int inten;
+	
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return -1;
+	}
+
+	inten = pspDisableInterrupts(); /* lock here to make thread safe */
+	for (i = 0; i < __PSP_FILENO_MAX; i++) {
+		if (__psp_descriptormap[i] == NULL) {
+			__psp_descriptormap[i] = &__psp_descriptor_data_pool[fd];
+			__psp_descriptormap[i]->ref_count++;
+			pspEnableInterrupts(inten); /* release lock */
+			return i;
+		}
+	}
+	pspEnableInterrupts(inten); /* release lock */
+	
+	errno = ENOMEM;
+	return -1;
+}
+
+void __psp_fdman_release_descriptor(int fd)
+{
+	if (!__PSP_IS_FD_VALID(fd)) {
+		errno = EBADF;
+		return;
+	}
+
+	__psp_descriptormap[fd]->ref_count--;
+	
+	if (__psp_descriptormap[fd]->ref_count == 0) {
+		
+		if (__psp_descriptormap[fd]->filename != NULL) {
+			free(__psp_descriptormap[fd]->filename);
+		}
+		__psp_descriptormap[fd]->filename       = NULL;
+		__psp_descriptormap[fd]->sce_descriptor = 0;
+		__psp_descriptormap[fd]->type           = 0;
+		__psp_descriptormap[fd]->flags          = 0;
+		
+	}
+	__psp_descriptormap[fd] = NULL;
+}
