--- jlint.cc.orig	Mon Aug 25 15:15:32 2003
+++ jlint.cc	Mon Aug 25 15:16:24 2003
@@ -37,7 +37,7 @@
 
 message_descriptor msg_table[] = {
 #define MSG(category, code, position_dependent, format) \
-{cat_##category, MSG_LOCATION_PREFIX##format, #code, position_dependent, true},
+{cat_##category, MSG_LOCATION_PREFIX format, #code, position_dependent, true},
 #include "jlint.msg"
   {cat_all}
 };
