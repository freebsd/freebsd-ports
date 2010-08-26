--- src/gettext.cpp~
+++ src/gettext.cpp
@@ -18,6 +18,12 @@
 
 #include <cstring>
 
+#ifndef ENABLE_NLS
+char *textdomain (const char *domainname) {
+  return "dummy";
+}
+#endif
+
 char const *egettext(char const *msgid)
 {
 	return msgid[0] == '\0' ? msgid : gettext(msgid);
