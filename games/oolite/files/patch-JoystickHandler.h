--- JoystickHandler.h.orig	Mon Oct 17 16:30:19 2005
+++ JoystickHandler.h	Mon Oct 17 16:30:52 2005
@@ -91,7 +91,7 @@
 #define ENUMKEY(x) [NSString stringWithFormat: @"%d", x]
 
 #import <Foundation/Foundation.h>
-#import <SDL/SDL.h>
+#import <SDL.h>
 
 @interface JoystickHandler : NSObject
 {
