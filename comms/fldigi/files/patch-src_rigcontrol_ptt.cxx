--- src/rigcontrol/ptt.cxx.orig	2023-08-31 22:56:35 UTC
+++ src/rigcontrol/ptt.cxx
@@ -69,7 +69,7 @@
 
 #include "n3fjp_logger.h"
 
-#include "cmedia.h"
+//#include "cmedia.h"
 
 LOG_FILE_SOURCE(debug::LOG_RIGCONTROL);
 
@@ -114,9 +114,11 @@ void PTT::reset(ptt_t dev)
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
@@ -178,6 +180,7 @@ void PTT::set(bool ptt)
 		set_uhrouter(ptt);
 		break;
 #endif
+#if 0
 	case PTT_CMEDIA:
 		if (cmedia_fd != -1) {
 			int bitnbr = 2;
@@ -188,6 +191,7 @@ void PTT::set(bool ptt)
 			set_cmedia(bitnbr, ptt);
 		}
 		break;
+#endif
 	default:
 		break;
 	}
