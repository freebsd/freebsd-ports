--- sysstr.c.orig	2012-01-03 09:51:23 UTC
+++ sysstr.c
@@ -74,7 +74,7 @@ str_chdir(const struct mystr* p_str)
 int
 str_open(const struct mystr* p_str, const enum EVSFSysStrOpenMode mode)
 {
-  enum EVSFSysUtilOpenMode open_mode = kVSFSysStrOpenUnknown;
+  enum EVSFSysUtilOpenMode open_mode = (enum EVSFSysUtilOpenMode) kVSFSysStrOpenUnknown;
   switch (mode)
   {
     case kVSFSysStrOpenReadOnly:
