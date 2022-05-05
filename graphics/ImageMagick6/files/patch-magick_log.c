--- magick/log.c.orig	2022-05-05 04:09:18 UTC
+++ magick/log.c
@@ -394,7 +394,7 @@ MagickExport void CloseMagickLog(void)
 %      const char *GetLogEventMask(void)
 %
 */
-MagickExport const LogEventType GetLogEventMask(void)
+MagickExport LogEventType GetLogEventMask(void)
 {
   ExceptionInfo
     *exception;
@@ -515,7 +515,7 @@ static int LogInfoCompare(const void *x,const void *y)
 }
 #endif
 
-MagickExport const LogInfo **GetLogInfoList(const char *pattern,
+MagickExport LogInfo **GetLogInfoList(const char *pattern,
   size_t *number_preferences,ExceptionInfo *exception)
 {
   const LogInfo
@@ -674,7 +674,7 @@ MagickExport char **GetLogList(const char *pattern,
 %      const char *GetLogName(void)
 %
 */
-MagickExport const char *GetLogName(void)
+MagickExport char *GetLogName(void)
 {
   return(log_name);
 }
@@ -1930,7 +1930,7 @@ MagickExport void SetLogMethod(MagickLogMethod method)
 %    o name: Specifies the new client name.
 %
 */
-MagickExport const char *SetLogName(const char *name)
+MagickExport char *SetLogName(const char *name)
 {
   if ((name != (char *) NULL) && (*name != '\0'))
     (void) CopyMagickString(log_name,name,MaxTextExtent);
