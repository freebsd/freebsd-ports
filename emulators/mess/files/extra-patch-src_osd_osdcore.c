--- src/osd/osdcore.c.orig	2014-10-05 09:30:10 UTC
+++ src/osd/osdcore.c
@@ -2,6 +2,10 @@
 #include "osdcore.h"
 #include "portmidi/portmidi.h"
 
+typedef struct __FILE_public FILEX;
+FILEX dummyval;
+FILEX * dummy = &dummyval;
+
 bool g_print_verbose = false;
 
 
@@ -10,9 +14,14 @@ bool g_print_verbose = false;
     for file output
 -------------------------------------------------*/
 
-void osd_file_output_callback(FILE *param, const char *format, va_list argptr)
+void osd_file_std_output_callback(FILEX *param, const char *format, va_list argptr)
+{
+	vfprintf(stdout, format, argptr);
+}
+
+void osd_file_err_output_callback(FILEX *param, const char *format, va_list argptr)
 {
-	vfprintf(param, format, argptr);
+	vfprintf(stderr, format, argptr);
 }
 
 
@@ -21,7 +30,7 @@ void osd_file_output_callback(FILE *para
     for no output
 -------------------------------------------------*/
 
-void osd_null_output_callback(FILE *param, const char *format, va_list argptr)
+void osd_null_std_output_callback(FILEX *param, const char *format, va_list argptr)
 {
 }
 
@@ -30,16 +39,16 @@ void osd_null_output_callback(FILE *para
 /* output channels */
 static output_delegate output_cb[OSD_OUTPUT_CHANNEL_COUNT] =
 {
-	output_delegate(FUNC(osd_file_output_callback), stderr),   // OSD_OUTPUT_CHANNEL_ERROR
-	output_delegate(FUNC(osd_file_output_callback), stderr),   // OSD_OUTPUT_CHANNEL_WARNING
-	output_delegate(FUNC(osd_file_output_callback), stdout),   // OSD_OUTPUT_CHANNEL_INFO
+	output_delegate(FUNC(osd_file_err_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_ERROR
+	output_delegate(FUNC(osd_file_err_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_WARNING
+	output_delegate(FUNC(osd_file_std_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_INFO
 #ifdef MAME_DEBUG
-	output_delegate(FUNC(osd_file_output_callback), stdout),   // OSD_OUTPUT_CHANNEL_DEBUG
+	output_delegate(FUNC(osd_file_std_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_DEBUG
 #else
-	output_delegate(FUNC(osd_null_output_callback), stdout),   // OSD_OUTPUT_CHANNEL_DEBUG
+	output_delegate(FUNC(osd_null_std_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_DEBUG
 #endif
-	output_delegate(FUNC(osd_file_output_callback), stdout),   // OSD_OUTPUT_CHANNEL_VERBOSE
-	output_delegate(FUNC(osd_file_output_callback), stdout)    // OSD_OUTPUT_CHANNEL_LOG
+	output_delegate(FUNC(osd_file_std_output_callback), dummy),   // OSD_OUTPUT_CHANNEL_VERBOSE
+	output_delegate(FUNC(osd_file_std_output_callback), dummy)    // OSD_OUTPUT_CHANNEL_LOG
 };
 
 
