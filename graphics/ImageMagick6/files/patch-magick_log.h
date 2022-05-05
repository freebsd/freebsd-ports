--- magick/log.h.orig	2022-05-05 04:04:28 UTC
+++ magick/log.h
@@ -66,14 +66,14 @@ typedef void
 extern MagickExport char
   **GetLogList(const char *,size_t *,ExceptionInfo *);
 
-extern MagickExport const char
+extern MagickExport char
   *GetLogName(void) magick_attribute((__pure__)),
   *SetLogName(const char *);
 
-extern MagickExport const LogEventType
+extern MagickExport LogEventType
   GetLogEventMask(void) magick_attribute((__pure__));
 
-extern MagickExport const LogInfo
+extern MagickExport LogInfo
   **GetLogInfoList(const char *,size_t *,ExceptionInfo *);
 
 extern MagickExport LogEventType
