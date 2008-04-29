--- Kernel/Base/AdLinkedList.h.orig	2006-11-02 14:42:45.000000000 +0100
+++ Kernel/Base/AdLinkedList.h	2008-04-29 09:14:45.000000000 +0200
@@ -25,6 +25,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 
 //! \brief Element for the linked lists.
 /**
