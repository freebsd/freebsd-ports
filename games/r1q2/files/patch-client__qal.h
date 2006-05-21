--- client/qal.h.orig	Sat Jun 26 15:20:12 2004
+++ client/qal.h	Thu May 18 20:40:19 2006
@@ -22,6 +22,10 @@
 #ifndef __QAL_H__
 #define __QAL_H__
 
+#undef ALCAPI
+#define ALCAPI
+#undef ALAPI
+#define ALAPI
 
 qboolean	QAL_Init (const char *driver);
 void		QAL_Shutdown (void);
