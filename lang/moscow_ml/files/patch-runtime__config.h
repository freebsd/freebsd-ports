--- runtime/config.h.orig	Mon Jan 19 16:02:21 2004
+++ runtime/config.h		Fri Feb  6 09:28:30 2004
@@ -1,27 +1,8 @@
 #ifndef _config_
 #define _config_
 
-
-#if defined(__MWERKS__) || defined(THINK_C)
 #include "m.h"
 #include "s.h"
-#else
-#ifdef macintosh
-#include ":::config:m.h"
-#include ":::config:s.h"
-#else
-#if defined(msdos)
-#include "../config.dos/m.h"
-#include "../config.dos/s.h"
-#elif defined(WIN32)
-#include "../config.w32/m.h"
-#include "../config.w32/s.h"
-#else
-#include "../config/m.h"
-#include "../config/s.h"
-#endif
-#endif
-#endif
 
 #ifdef WIN32
 
