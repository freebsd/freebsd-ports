--- chrome/browser/ui/views/frame/browser_view.h.orig	2019-04-08 08:32:47 UTC
+++ chrome/browser/ui/views/frame/browser_view.h
@@ -50,7 +50,7 @@
 #include "chrome/browser/ui/views/intent_picker_bubble_view.h"
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "chrome/browser/ui/views/quit_instruction_bubble_controller.h"
 #endif
 
@@ -853,7 +853,7 @@ class BrowserView : public BrowserWindow,
   };
   base::Optional<ResizeSession> interactive_resize_;
 
-#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   scoped_refptr<QuitInstructionBubbleController>
       quit_instruction_bubble_controller_;
 #endif
