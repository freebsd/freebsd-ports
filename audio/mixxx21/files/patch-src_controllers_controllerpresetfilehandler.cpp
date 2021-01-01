--- src/controllers/controllerpresetfilehandler.cpp.orig	2015-12-29 16:10:41 UTC
+++ src/controllers/controllerpresetfilehandler.cpp
@@ -43,7 +43,11 @@ ControllerPresetPointer ControllerPreset
         pHandler = new MidiControllerPresetFileHandler();
     } else if (scriptPath.endsWith(HID_PRESET_EXTENSION, Qt::CaseInsensitive) ||
                scriptPath.endsWith(BULK_PRESET_EXTENSION, Qt::CaseInsensitive)) {
+#if __HID__
         pHandler = new HidControllerPresetFileHandler();
+#else
+        return ControllerPresetPointer();
+#endif
     }
 
     if (pHandler == NULL) {
