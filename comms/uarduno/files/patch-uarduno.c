--- uarduno.c.orig	2022-07-26 16:34:54 UTC
+++ uarduno.c
@@ -242,7 +242,11 @@ static driver_t uarduno_driver =
   sizeof(struct uarduno_softc)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(uarduno, uhub, uarduno_driver, usbd_driver_load, NULL);
+#else
 DRIVER_MODULE(uarduno, uhub, uarduno_driver, ucom_devclass, usbd_driver_load, 0);
+#endif
 MODULE_DEPEND(uarduno, usb, 1, 1, 1);
 MODULE_DEPEND(uarduno, ucom, UCOM_MINVER, UCOM_PREFVER, UCOM_MAXVER);
 MODULE_VERSION(uarduno, UARDUNO_MODVER);
@@ -1120,8 +1124,6 @@ static device_method_t uarduno_methods[] =
   {0, 0}
 };
 
-static devclass_t uarduno_devclass;
-
 static driver_t uarduno_driver =
 {
   .name = "uarduno",
@@ -1129,7 +1131,13 @@ static driver_t uarduno_driver =
   .size = sizeof(struct uarduno_softc),
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(uarduno, uhub, uarduno_driver, NULL, NULL);
+#else
+static devclass_t uarduno_devclass;
+
 DRIVER_MODULE(uarduno, uhub, uarduno_driver, uarduno_devclass, NULL, 0);
+#endif
 MODULE_DEPEND(uarduno, ucom, 1, 1, 1);
 MODULE_DEPEND(uarduno, usb, 1, 1, 1);
 MODULE_VERSION(uarduno, UARDUNO_MODVER);
