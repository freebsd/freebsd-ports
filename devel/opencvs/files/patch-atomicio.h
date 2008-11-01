--- atomicio.h	17 Sep 2007 10:07:21 -0000	1.1
+++ atomicio.h	17 Oct 2008 08:51:45 -0000
@@ -1,4 +1,4 @@
-/* $OpenBSD: atomicio.h,v 1.1 2007/09/17 10:07:21 tobias Exp $ */
+/* $OpenBSD: atomicio.h,v 1.10 2006/08/03 03:34:41 deraadt Exp $ */
 
 /*
  * Copyright (c) 2006 Damien Miller.  All rights reserved.
@@ -35,5 +35,11 @@
 size_t	atomicio(ssize_t (*)(int, void *, size_t), int, void *, size_t);
 
 #define vwrite (ssize_t (*)(int, void *, size_t))write
+
+/*
+ * ensure all of data on socket comes through. f==readv || f==writev
+ */
+size_t	atomiciov(ssize_t (*)(int, const struct iovec *, int),
+    int, const struct iovec *, int);
 
 #endif /* _ATOMICIO_H */
