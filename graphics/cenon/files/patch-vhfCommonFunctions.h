--- VHFShared/vhfCommonFunctions.h.orig	Sun Dec 12 16:25:57 2004
+++ VHFShared/vhfCommonFunctions.h	Tue Apr 25 17:18:43 2006
@@ -36,6 +36,8 @@
 #ifndef VHF_H_COMMONFUNCTIONS
 #define VHF_H_COMMONFUNCTIONS
 
+#include <AppKit/AppKit.h>
+
 #include "types.h"
 
 /* Timers used to automatically scroll when the mouse is
@@ -44,7 +46,7 @@
 #define StartTimer(inTimerLoop) if (!inTimerLoop) { [NSEvent startPeriodicEventsAfterDelay:0.1 withPeriod:0.01]; inTimerLoop=YES; }
 #define StopTimer(inTimerLoop) if (inTimerLoop) { [NSEvent stopPeriodicEvents]; inTimerLoop=NO; }
 
-void		sortPopup(id popupButton, int startIx);
+void		sortPopup(NSPopUpButton *popupButton, int startIx);
 
 NSString	*stringWithConvertedChars(NSString *string, NSDictionary *conversionDict);
 
