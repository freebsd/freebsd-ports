--- gtab-buf.cpp.orig	2018-05-21 12:35:13 UTC
+++ gtab-buf.cpp
@@ -1242,7 +1242,7 @@ gboolean gtab_pre_select_shift(KeySym key, int kbstate
   // If the key(123) is not defined as gtab keys, the shift keys(!@#) should be used for punc, not preselect
   int c;
   char *p;
-  if (p=strchr(cur_inmd->selkey, key)) {
+  if ((p=strchr(cur_inmd->selkey, key))) {
     c = p - cur_inmd->selkey;
     return gtab_pre_select_idx(c);
   } else
