--- src/clients/lib/java/include/callbacks.h.orig	Mon Mar 27 11:34:45 2006
+++ src/clients/lib/java/include/callbacks.h	Sat Apr  8 00:27:56 2006
@@ -14,6 +14,13 @@
  *  Lesser General Public License for more details.
  */
 
+#ifndef __CALLBACKS_H__
+#define __CALLBACKS_H__
+
+#ifdef __cplusplus
+{
+#endif
+
 #include <xmmsclient/xmmsclient.h>
 #include <jni.h>
 
@@ -67,3 +74,8 @@
 extern void callback_dict_foreach_function(const void *key, xmmsc_result_value_type_t type, const void *value, void *user_data);
 extern void callback_propdict_foreach_function(const void *key, xmmsc_result_value_type_t type, const void *value, const char *source, void *user_data);
 
+#ifdef __cplusplus
+}
+#endif
+
+#endif
