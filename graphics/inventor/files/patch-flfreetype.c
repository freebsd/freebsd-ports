*** libFL/ang/flfreetype.c.orig	Thu Jan  2 17:04:33 2003
--- libFL/ang/flfreetype.c	Thu Jan  2 17:11:09 2003
***************
*** 318,324 ****
--- 318,328 ----
  {
    FLfontStruct *fs;
    FLbitmap *bitmap;
+ #if BYTE_ORDER == LITTLE_ENDIAN
+   GLuint c = (UCS2[1] << 8) | UCS2[0];
+ #else
    GLuint c = (UCS2[0] << 8) | UCS2[1];
+ #endif
  
    TRACE(("_flFTUniGetBitmap: 0x%04x\n", c));
    while ((fs = *fsList++))
***************
*** 333,339 ****
--- 337,347 ----
  {
    FLfontStruct *fs;
    FLoutline *outline;
+ #if BYTE_ORDER == LITTLE_ENDIAN
+   GLuint c = (UCS2[1] << 8) | UCS2[0];
+ #else
    GLuint c = (UCS2[0] << 8) | UCS2[1];
+ #endif
  
    TRACE(("_flFTUniGetOutline: 0x%04x\n", c));
    while ((fs = *fsList++))
