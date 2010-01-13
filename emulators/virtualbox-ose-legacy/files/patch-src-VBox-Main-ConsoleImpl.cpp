--- src/VBox/Main/ConsoleImpl.cpp.orig
+++ src/VBox/Main/ConsoleImpl.cpp
@@ -6168,7 +6168,7 @@ Console::usbDetachCallback(Console *that
 }
 
 #endif /* VBOX_WITH_USB */
-#if (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)) && !defined(VBOX_WITH_NETFLT)
+#if ((defined(RT_OS_LINUX) && !defined(VBOX_WITH_NETFLT)) || defined(RT_OS_FREEBSD))
 
 /**
  * Helper function to handle host interface device creation and attachment.
