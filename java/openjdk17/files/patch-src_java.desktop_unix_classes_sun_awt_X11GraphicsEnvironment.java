--- src/java.desktop/unix/classes/sun/awt/X11GraphicsEnvironment.java
+++ src/java.desktop/unix/classes/sun/awt/X11GraphicsEnvironment.java
@@ -232,7 +232,7 @@ public final class X11GraphicsEnvironment extends SunGraphicsEnvironment {
             throw new AWTError("no screen devices");
         }
         int index = getDefaultScreenNum();
-        mainScreen = 0 < index && index < screens.length ? index : 0;
+        mainScreen = 0 < index && index < numScreens ? index : 0;
 
         for (int id = 0; id < numScreens; ++id) {
             devices.put(id, old.containsKey(id) ? old.remove(id) :
