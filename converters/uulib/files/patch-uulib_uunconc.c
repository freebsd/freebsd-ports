diff -r -u ../../orig/uudeview-0.5.18/uulib/uunconc.c uulib/uunconc.c
--- ../../orig/uudeview-0.5.18/uulib/uunconc.c	Tue Apr  2 05:04:52 2002
+++ uulib/uunconc.c	Sun Sep  1 21:27:01 2002
@@ -1264,7 +1264,7 @@
   else
     mode = "wb";	/* otherwise in binary          */
 
-  if ((data->binfile = tempnam (NULL, "uu")) == NULL) {
+  if ((data->binfile = _FP_tempnam (NULL, "uu")) == NULL) {
     UUMessage (uunconc_id, __LINE__, UUMSG_ERROR,
 	       uustring (S_NO_TEMP_NAME));
     return UURET_NOMEM;
@@ -1426,7 +1426,7 @@
    */
 
   if (data->uudet == BH_ENCODED && data->binfile) {
-    if ((ntmp = tempnam (NULL, "uu")) == NULL) {
+    if ((ntmp = _FP_tempnam (NULL, "uu")) == NULL) {
       UUMessage (uunconc_id, __LINE__, UUMSG_ERROR,
 		 uustring (S_NO_TEMP_NAME));
       progress.action = 0;
