--- newlib/libc/sys/psp/fdman.h.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/fdman.h	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,44 @@
+/*
+ * PSP Software Development Kit - http://www.pspdev.org
+ * -----------------------------------------------------------------------
+ * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
+ *
+ * fdman.h - File descriptor management.
+ *
+ * Copyright (c) 2006 Rafael Cabezas <rafpsp@gmail.com>
+ */
+
+#ifndef _FDMAN_H_
+	#define _FDMAN_H_
+	
+	#define __PSP_FILENO_MAX 1024
+
+	#define __PSP_IS_FD_VALID(FD) \
+			( (FD >= 0) && (FD < __PSP_FILENO_MAX) && (__psp_descriptormap[FD] != NULL) )
+
+	#define __PSP_IS_FD_OF_TYPE(FD, TYPE) \
+			( (__PSP_IS_FD_VALID(FD)) && (__psp_descriptormap[FD]->type == TYPE) )
+			
+	typedef enum {
+		__PSP_DESCRIPTOR_TYPE_FILE  ,
+		__PSP_DESCRIPTOR_TYPE_PIPE ,
+		__PSP_DESCRIPTOR_TYPE_SOCKET,
+		__PSP_DESCRIPTOR_TYPE_TTY
+	} __psp_fdman_fd_types;
+	
+	typedef struct {
+		char * filename;
+		u8     type;
+		u32    sce_descriptor;
+		u32    flags;
+		u32    ref_count;
+	} __psp_descriptormap_type;
+	 
+	extern __psp_descriptormap_type *__psp_descriptormap[__PSP_FILENO_MAX];
+	
+	void __psp_fdman_init();
+	int  __psp_fdman_get_new_descriptor();
+	int  __psp_fdman_get_dup_descriptor(int fd);
+	void __psp_fdman_release_descriptor(int fd);
+
+#endif
