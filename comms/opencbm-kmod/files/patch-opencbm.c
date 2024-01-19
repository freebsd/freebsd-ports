--- opencbm.c.orig	2022-01-22 22:01:25 UTC
+++ opencbm.c
@@ -133,8 +133,6 @@ static struct cdevsw cbm_cdevsw = {
     .d_name = CBM_NAME
 };
 
-static devclass_t cbm_devclass;
-
 /* forward references for parallel burst routines */
 int cbm_parallel_burst_read_track(struct cbm_data *sc, device_t ppbus,
         unsigned char *buffer);
@@ -699,7 +697,7 @@ cbm_ioctl(struct cdev *dev, u_long cmd, caddr_t data, 
                     break;
                 }
                 rv = !cbm_parallel_burst_read_track(sc, ppbus, sc->sc_buf);
-                if (!rv) copyout(sc->sc_buf, val->buffer, BUFFER_SIZE);
+                if (!rv) rv = copyout(sc->sc_buf, val->buffer, BUFFER_SIZE);
                 break;
 
         case CBMCTRL_PARBURST_READ_TRACK_VAR:
@@ -710,7 +708,7 @@ cbm_ioctl(struct cdev *dev, u_long cmd, caddr_t data, 
                     break;
                 }
                 rv = !cbm_parallel_burst_read_track_var(sc, ppbus, sc->sc_buf);
-                if (!rv) copyout(sc->sc_buf, val->buffer, BUFFER_SIZE);
+                if (!rv) rv = copyout(sc->sc_buf, val->buffer, BUFFER_SIZE);
                 break;
 
         case CBMCTRL_PARBURST_WRITE_TRACK:
@@ -720,7 +718,9 @@ cbm_ioctl(struct cdev *dev, u_long cmd, caddr_t data, 
                     rv = EINVAL;
                     break;
                 }
-                copyin(val->buffer, sc->sc_buf, val->length);
+                rv = copyin(val->buffer, sc->sc_buf, val->length);
+                if (rv)
+                    break;
                 rv = !cbm_parallel_burst_write_track(sc, ppbus,
                         val->buffer, val->length);
                 break;
@@ -930,7 +930,13 @@ static driver_t cbm_driver = {
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
