--- src/rigcontrol/ptt.cxx.orig	2021-07-01 19:51:31 UTC
+++ src/rigcontrol/ptt.cxx
@@ -69,7 +69,7 @@
 
 #include "n3fjp_logger.h"
 
-#include "cmedia.h"
+//#include "cmedia.h"
 
 LOG_FILE_SOURCE(debug::LOG_RIGCONTROL);
 
@@ -116,9 +116,11 @@ void PTT::reset(ptt_t dev)
 	case PTT_TTY:
 		open_tty();
 		break;
+#if 0
 	case PTT_CMEDIA:
 		cmedia_fd = open_cmedia(progdefaults.cmedia_device);
 		break;
+#endif
 	default:
 		break; // nothing to open
 	}
@@ -174,6 +176,7 @@ void PTT::set(bool ptt)
 		set_uhrouter(ptt);
 		break;
 #endif
+#if 0
 	case PTT_CMEDIA:
 		if (cmedia_fd != -1) {
 			int bitnbr = 2;
@@ -184,6 +187,7 @@ void PTT::set(bool ptt)
 			set_cmedia(bitnbr, ptt);
 		}
 		break;
+#endif
 	default:
 		{
 			set_gpio(ptt);
