--- form_wrap.h.orig	Sat Jul 31 17:54:47 2004
+++ form_wrap.h	Thu Aug 12 18:09:07 2004
@@ -26,6 +26,11 @@
 #include <form.h>
 #include <ruby.h>
 
+#ifndef __cplusplus
+#define false   0
+#define true    1
+#endif
+
 extern VALUE mForm;
 extern VALUE cFIELD;
 extern VALUE cFIELDTYPE;
