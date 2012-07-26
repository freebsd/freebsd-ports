--- sysstr.c.orig	2011-12-14 18:26:39.000000000 +0800
+++ sysstr.c	2012-07-24 11:27:18.000000000 +0800
@@ -74,7 +74,7 @@
 int
 str_open(const struct mystr* p_str, const enum EVSFSysStrOpenMode mode)
 {
-  enum EVSFSysUtilOpenMode open_mode = kVSFSysStrOpenUnknown;
+  enum EVSFSysUtilOpenMode open_mode = (enum EVSFSysUtilOpenMode) kVSFSysStrOpenUnknown;
   switch (mode)
   {
     case kVSFSysStrOpenReadOnly:
