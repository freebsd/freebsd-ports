--- src/arch/gtk3/joystickdrv/joystick_bsd.c.orig	2025-12-24 18:51:33 UTC
+++ src/arch/gtk3/joystickdrv/joystick_bsd.c
@@ -643,18 +643,20 @@ void joystick_arch_init(void)
         joydev = scan_device(node);
         if (joydev != NULL) {
             joy_priv_t *priv;
+            char *backup_name;
 
             log_message(bsd_joy_log, "%s: %s", joydev->node, joydev->name);
 
             /* scan axes, buttons and hats */
             if (scan_inputs(joydev)) {
                 /* OK: try to register */
+                backup_name = lib_strdup(joydev->name);
                 if (!joystick_device_register(joydev)) {
                     /* failure */
+                    /* joydev is already destroyed */
                     log_warning(bsd_joy_log,
                                 "failed to register device %s (\"%s\")",
-                                joydev->node, joydev->name);
-                    joystick_device_free(joydev);
+                                node, backup_name);
                 } else {
                     priv = joydev->priv;
                     /* allocate arrays for previous input states */
@@ -665,6 +667,7 @@ void joystick_arch_init(void)
                     priv->prev_hats    = lib_calloc((size_t)joydev->num_hats,
                                                     sizeof *priv->prev_hats);
                 }
+                lib_free(backup_name);
             } else {
                 /* failure while scanning: log and free invalid device */
                 log_warning(bsd_joy_log,
