--- opencbm/sys/freebsd/opencbm.c.orig	2022-05-13 16:48:06 UTC
+++ opencbm/sys/freebsd/opencbm.c
@@ -133,8 +133,6 @@ static struct cdevsw cbm_cdevsw = {
     .d_name = CBM_NAME
 };
 
-static devclass_t cbm_devclass;
-
 /* forward references for parallel burst routines */
 int cbm_parallel_burst_read_track(struct cbm_data *sc, device_t ppbus,
         unsigned char *buffer);
@@ -930,7 +928,13 @@ static driver_t cbm_driver = {
     sizeof(struct cbm_data)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(cbm, ppbus, cbm_driver, 0, 0);
+#else
+static devclass_t cbm_devclass;
+
 DRIVER_MODULE(cbm, ppbus, cbm_driver, cbm_devclass, 0, 0);
+#endif
 MODULE_DEPEND(cbm, ppbus, 1, 1, 1);
 
 /*
