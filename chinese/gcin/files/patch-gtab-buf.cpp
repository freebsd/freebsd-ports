--- gtab-buf.cpp.orig	2020-03-14 07:23:09 UTC
+++ gtab-buf.cpp
@@ -1253,7 +1253,7 @@ gboolean gtab_pre_select_shift(KeySym key, int kbstate
   // If the key(123) is not defined as gtab keys, the shift keys(!@#) should be used for punc, not preselect
   int c;
   char *p;
-  if (p=strchr(cur_inmd->selkey, key)) {
+  if ((p=strchr(cur_inmd->selkey, key))) {
     c = p - cur_inmd->selkey;
     return gtab_pre_select_idx(c);
   } else
