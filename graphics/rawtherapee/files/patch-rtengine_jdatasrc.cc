This is a combinediff of 
https://github.com/Beep6581/RawTherapee/pull/7080/commits/efdc5bce3b9794847093baeb040937ab55eba86e
https://github.com/Beep6581/RawTherapee/pull/7080/commits/7789a8574b454ebd874522a70930ae4b40726da4

--- rtengine/jdatasrc.cc.orig	2024-02-16 05:12:09 UTC
+++ rtengine/jdatasrc.cc
@@ -247,20 +247,6 @@ my_error_exit (j_common_ptr cinfo)
 #endif
 }
 
-
-#ifdef _WIN32
-#define JVERSION	"6b  27-Mar-1998"
-#define JCOPYRIGHT_SHORT	"(C) 1998, Thomas G. Lane"
-#define JMESSAGE(code,string)	string ,
-
-const char * const jpeg_std_message_table[] = {
-#include "jerror.h"
-  NULL
-};
-#else
-extern const char * const jpeg_std_message_table[];
-#endif
-
 /*
  * Actual output of an error or trace message.
  * Applications may override this method to send JPEG messages somewhere
@@ -409,24 +395,10 @@ my_jpeg_std_error (struct jpeg_error_mgr * err)
 GLOBAL(struct jpeg_error_mgr *)
 my_jpeg_std_error (struct jpeg_error_mgr * err)
 {
+    err = jpeg_std_error(err);
 
+    /* override these functions */
     err->error_exit = my_error_exit;
-    err->emit_message = emit_message;
-    err->output_message = output_message;
-    err->format_message = format_message;
-    err->reset_error_mgr = reset_error_mgr;
-
-    err->trace_level = 0;     /* default = no tracing */
-    err->num_warnings = 0;    /* no warnings emitted yet */
-    err->msg_code = 0;        /* may be useful as a flag for "no error" */
-
-    /* Initialize message table pointers */
-    err->jpeg_message_table = jpeg_std_message_table;
-    err->last_jpeg_message = (int) JMSG_LASTMSGCODE - 1;
-
-    err->addon_message_table = nullptr;
-    err->first_addon_message = 0; /* for safety */
-    err->last_addon_message = 0;
 
     return err;
 }
