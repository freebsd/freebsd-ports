diff -ur /usr/Arch/Nokia/Gammu/gammu-0.90.0/common/phone/at/sonyeric.c ./common/phone/at/sonyeric.c
--- /usr/Arch/Nokia/Gammu/gammu-0.90.0/common/phone/at/sonyeric.c	Sun Nov  2 11:45:40 2003
+++ ./common/phone/at/sonyeric.c	Tue Dec  9 17:36:22 2003
@@ -1,7 +1,6 @@
                                            
 #include "../../gsmstate.h"
 
-#ifdef GSM_ENABLE_ATGEN
 
 #include <string.h>
 #include <time.h>
@@ -13,7 +12,6 @@
 extern GSM_Reply_Function 		ATGENReplyFunctions[];
 extern GSM_Error ATGEN_DispatchMessage	(GSM_StateMachine *s);
 
-#ifdef GSM_ENABLE_OBEXGEN
 
 extern GSM_Reply_Function 		OBEXGENReplyFunctions[];
 extern GSM_Error OBEXGEN_GetFilePart	(GSM_StateMachine *s, GSM_File *File);
@@ -403,8 +401,6 @@
 #endif
 }
 
-#endif
-#endif
 
 /* How should editor hadle tabs in this file? Add editor commands here.
  * vim: noexpandtab sw=8 ts=8 sts=8:
