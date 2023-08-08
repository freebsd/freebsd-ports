--- src/arch/gtk3/joystickdrv/joystick_bsd.c.orig	2022-12-27 23:56:56 UTC
+++ src/arch/gtk3/joystickdrv/joystick_bsd.c
@@ -203,7 +203,7 @@ static void usb_joystick(int jp, void* priv)
     }
     if (ret != -1 && errno != EAGAIN) {
         /* XXX */
-        log_warning("strange read return: %zd/%d", ret, errno);
+        log_warning(bsd_joystick_log, "strange read return: %zd/%d", ret, errno);
         return;
     }
     if (!val) {
