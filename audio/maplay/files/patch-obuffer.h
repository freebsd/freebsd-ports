--- obuffer.h.orig	Thu Jun 23 22:14:40 1994
+++ obuffer.h	Thu Nov 21 16:35:11 2002
@@ -27,7 +27,7 @@
 #ifndef OBUFFER_H
 #define OBUFFER_H
 
-#include <iostream.h>
+#include <iostream>
 #include <unistd.h>
 #include <stdlib.h>
 #include "all.h"
@@ -123,20 +123,20 @@
 
 public:
 #ifdef ULAW
-	SparcObuffer (Header *, bool use_speaker, bool use_headphone, bool use_line_out);
+	SparcObuffer (Header *, boolean use_speaker, boolean use_headphone, boolean use_line_out);
 #else
 	SparcObuffer (uint32 number_of_channels, Header *,
- 		      bool use_speaker, bool use_headphone, bool use_line_out);
+ 		      boolean use_speaker, boolean use_headphone, boolean use_line_out);
 #endif
        ~SparcObuffer (void);
   void	append (uint32 channel, int16 value);
   void	write_buffer (int dummy);
 
 #ifdef ULAW
-  static bool class_suitable (uint32 number_of_channels, bool force_amd);
+  static boolean class_suitable (uint32 number_of_channels, boolean force_amd);
 	// returnvalue == False: no u-law output possible (class unsuitable)
 #else
-  static bool class_suitable (void);
+  static boolean class_suitable (void);
 	// returnvalue == False: no 16-bit output possible (class unsuitable)
 #endif
 };
@@ -159,7 +159,7 @@
   void	append (uint32 channel, int16 value);
   void	write_buffer (int dummy);
 
-  static bool class_suitable (uint32 number_of_channels);
+  static boolean class_suitable (uint32 number_of_channels);
 };
 #endif	// LINUX
 
