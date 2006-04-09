--- src/clients/lib/java/include/misc.h.orig	Mon Mar 27 11:34:45 2006
+++ src/clients/lib/java/include/misc.h	Sat Apr  8 00:27:56 2006
@@ -14,8 +14,21 @@
  *  Lesser General Public License for more details.
  */
 
+#ifndef __MISC_H__
+#define __MISC_H__
+
+#ifdef __cplusplus
+{
+#endif
+
 #include <xmmsclient/xmmsclient.h>
 #include <jni.h>
 
 extern xmmsc_result_t* getResultFromPointer(jlong val);
 extern jlong getPointerToConnection(xmmsc_connection_t *c);
+
+#ifdef __cplusplus
+}
+#endif
+
+#endif
