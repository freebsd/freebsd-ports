--- sys/dev/ltmdm/ltmdmsio.c.orig	Tue Mar 12 04:47:31 2002
+++ sys/dev/ltmdm/ltmdmsio.c	Tue Jul 27 23:28:56 2004
@@ -60,7 +60,9 @@
 #include <sys/proc.h>
 #include <sys/module.h>
 #include <sys/conf.h>
+#if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
+#endif
 #include <sys/fcntl.h>
 #include <sys/interrupt.h>
 #include <sys/kernel.h>
@@ -69,12 +71,21 @@
 #include <machine/bus.h>
 #include <sys/rman.h>
 #if __FreeBSD_version >= 500000
+#if __FreeBSD_version <  500034 /* < 20020426 */
 #include <sys/timetc.h>
 #endif
+#endif
+#ifdef ENABLE_PPS
 #include <sys/timepps.h>
+#endif
 
+#if __FreeBSD_version >= 500000
+#include <dev/pci/pcireg.h>
+#include <dev/pci/pcivar.h>
+#else
 #include <pci/pcireg.h>
 #include <pci/pcivar.h>
+#endif
 
 #include <machine/clock.h>
 
@@ -88,7 +99,9 @@
 
 #include <machine/resource.h>
 
-#if __FreeBSD_version >= 500027  /* >= 20011022 */
+#if __FreeBSD_version >= 501107  /* >= 20030917 */
+#include <dev/ic/ns16550.h>
+#elif __FreeBSD_version >= 500027  /* >= 20011022 */
 #include <dev/sio/sioreg.h>
 #else
 #include <isa/sioreg.h>
@@ -124,9 +137,11 @@
 #endif
 
 #if __FreeBSD_version >= 500023 /* >= 20010912 */
-#define proc thread         /* temporary hack: struct proc -> stuct thread */
+#define proc thread         /* XXX  struct proc -> stuct thread */
+#if __FreeBSD_version <  500033 /* <  20020401 */
 #define suser(p) suser_td(p)
 #endif
+#endif
 
 
 #define LOTS_OF_EVENTS  64  /* helps separate urgent events from input */
@@ -230,7 +245,9 @@
     u_char  last_modem_status;  /* last MSR read by intr handler */
     u_char  prev_modem_status;  /* last MSR handled by high level */
 
+#if __FreeBSD_version < 502119
     u_char  hotchar;        /* ldisc-specific char to be handled ASAP */
+#endif
     u_char  *ibuf;          /* start of input buffer */
     u_char  *ibufend;       /* end of input buffer */
     u_char  *ibufold;       /* old input buffer, to be freed */
@@ -256,7 +273,9 @@
     bool_t  do_dcd_timestamp;
     struct timeval  timestamp;
     struct timeval  dcd_timestamp;
+#ifdef ENABLE_PPS
     struct  pps_state pps;
+#endif
 
     u_long  bytes_in;       /* statistics */
     u_long  bytes_out;
@@ -268,7 +287,11 @@
     struct resource *iores[6];
     struct resource *irqres;
     void *cookie;
+#if __FreeBSD_version > 502115
+    struct cdev *devs[6];
+#else
     dev_t devs[6];
+#endif
 
     /*
      * Data area for output buffers.  Someday we should build the output
@@ -352,6 +375,7 @@
 #endif
 
 static struct cdevsw sio_cdevsw = {
+#if __FreeBSD_version < 500105
     /* open */  sioopen,
     /* close */ sioclose,
     /* read */  sioread,
@@ -361,7 +385,11 @@
     /* mmap */  nommap,
     /* strategy */  nostrategy,
     /* name */  driver_name,
+#ifdef MAJOR_AUTO
+    /* maj */   MAJOR_AUTO,
+#else
     /* maj */   CDEV_MAJOR,
+#endif
     /* dump */  nodump,
     /* psize */ nopsize,
 #if __FreeBSD_version < 430000
@@ -373,10 +401,30 @@
     /* bmaj */  -1,
     /* kqfilter */  ttykqfilter,
 #else /* __FreeBSD_version >= 500000 */
-    /* flags */ D_TTY | D_KQFILTER,
+    /* flags */ D_TTY,
     /* kqfilter */  ttykqfilter,
 #endif
 #endif
+#else
+    .d_open = sioopen,
+    .d_close = sioclose,
+    .d_read = sioread,
+    .d_write = siowrite,
+    .d_ioctl = sioioctl,
+    .d_name = driver_name,
+#ifdef MAJOR_AUTO
+    .d_maj = MAJOR_AUTO,
+#else
+    .d_maj = CDEV_MAJOR,
+#endif
+    .d_kqfilter = ttykqfilter,
+#if __FreeBSD_version >= 502102
+    .d_flags = D_TTY | D_NEEDGIANT,
+    .d_version = D_VERSION
+#else
+    .d_poll = ttypoll,
+#endif
+#endif
 };
 
 static  u_int   com_events; /* input chars + weighted output completions */
@@ -1295,8 +1343,11 @@
     DPRINTF(1,("  x_chip_version    = %d\n", x_chip_version));
 
     com->flags = flags;
+
+#ifdef ENABLE_PPS
     com->pps.ppscap = PPS_CAPTUREASSERT | PPS_CAPTURECLEAR;
     pps_init(&com->pps);
+#endif
 
     /*
      * initialize the device registers as follows:
@@ -1433,11 +1484,19 @@
 
     s = splfunc();
     if (tp) {
+#if __FreeBSD_version > 502112
+        (*linesw[tp->t_line]->l_close)(tp, FNONBLOCK);
+#else
         (*linesw[tp->t_line].l_close)(tp, FNONBLOCK);
+#endif
         disc_optim(tp, &tp->t_termios, com);
         comstop(tp, FREAD | FWRITE);
         comhardclose(com);
+#if __FreeBSD_version < 502122
         ttyclose(tp);
+#else
+        ttygone(tp);
+#endif
     }
     vxdPortClose();
     siosettimeout();
@@ -1470,7 +1529,11 @@
 }
 
 static int
+#if __FreeBSD_version > 502115
+sioopen(struct cdev *dev, int flag, int mode, struct proc *p)
+#else
 sioopen(dev_t dev, int flag, int mode, struct proc *p)
+#endif
 {
     struct com_s    *com;
     int     error;
@@ -1610,7 +1673,11 @@
          * the true carrier.
          */
         if (com->prev_modem_status & MSR_DCD || mynor & CALLOUT_MASK)
+#if __FreeBSD_version > 502112
+            (*linesw[tp->t_line]->l_modem)(tp, 1);
+#else
             (*linesw[tp->t_line].l_modem)(tp, 1);
+#endif
     }
     /*
      * Wait for DCD if necessary.
@@ -1626,7 +1693,11 @@
             goto out;
         goto open_top;
     }
+#if __FreeBSD_version > 502112
+    error = (*linesw[tp->t_line]->l_open)(dev, tp);
+#else
     error = (*linesw[tp->t_line].l_open)(dev, tp);
+#endif
     disc_optim(tp, &tp->t_termios, com);
     if (tp->t_state & TS_ISOPEN && mynor & CALLOUT_MASK)
         com->active_out = TRUE;
@@ -1639,7 +1710,11 @@
 }
 
 static int
+#if __FreeBSD_version > 502115
+sioclose(struct cdev *dev, int flag, int mode, struct proc *p)
+#else
 sioclose(dev_t dev, int flag, int mode, struct proc *p)
+#endif
 {
     struct com_s    *com;
     int     mynor;
@@ -1654,11 +1729,19 @@
         return (ENODEV);
     tp = com->tp;
     s = splfunc();
+#if __FreeBSD_version > 502112
+    (*linesw[tp->t_line]->l_close)(tp, flag);
+#else
     (*linesw[tp->t_line].l_close)(tp, flag);
+#endif
     disc_optim(tp, &tp->t_termios, com);
     comstop(tp, FREAD | FWRITE);
     comhardclose(com);
+#if __FreeBSD_version < 502122
     ttyclose(tp);
+#else
+    tty_close(tp);
+#endif
     siosettimeout();
     splx(s);
     if (com->gone) {
@@ -1685,7 +1768,9 @@
     s = splfunc();
     com->do_timestamp = FALSE;
     com->do_dcd_timestamp = FALSE;
+#ifdef ENABLE_PPS
     com->pps.ppsparam.mode = 0;
+#endif
     write_vuart_port(UART_CFCR, com->cfcr_image &= ~CFCR_SBREAK);
     {
         write_vuart_port(UART_IER, 0);
@@ -1724,7 +1809,11 @@
 }
 
 static int
+#if __FreeBSD_version > 502115
+sioread(struct cdev *dev, struct uio *uio, int flag)
+#else
 sioread(dev_t dev, struct uio *uio, int flag)
+#endif
 {
     int     mynor;
     struct com_s    *com;
@@ -1735,11 +1824,19 @@
     com = com_addr(MINOR_TO_UNIT(mynor));
     if (com == NULL || com->gone)
         return (ENODEV);
+#if __FreeBSD_version > 502112
+    return ((*linesw[com->tp->t_line]->l_read)(com->tp, uio, flag));
+#else
     return ((*linesw[com->tp->t_line].l_read)(com->tp, uio, flag));
+#endif
 }
 
 static int
+#if __FreeBSD_version > 502115
+siowrite(struct cdev *dev, struct uio *uio, int flag)
+#else
 siowrite(dev_t dev, struct uio *uio, int flag)
+#endif
 {
     int     mynor;
     struct com_s    *com;
@@ -1754,7 +1851,11 @@
     if (com == NULL || com->gone)
         return (ENODEV);
 
+#if __FreeBSD_version > 502112
+    return ((*linesw[com->tp->t_line]->l_write)(com->tp, uio, flag));
+#else
     return ((*linesw[com->tp->t_line].l_write)(com->tp, uio, flag));
+#endif
 }
 
 static void
@@ -1860,7 +1961,11 @@
                 if (line_status & LSR_PE)
                     recv_data |= TTY_PE;
             }
+#if __FreeBSD_version > 502112
+            (*linesw[tp->t_line]->l_rint)(recv_data, tp);
+#else
             (*linesw[tp->t_line].l_rint)(recv_data, tp);
+#endif
             lt_disable_intr();
         } while (buf < com->iptr);
     }
@@ -1894,23 +1999,34 @@
     u_char  recv_data;
     u_char  int_ctl;
     u_char  int_ctl_new;
+#ifdef ENABLE_PPS
+#if __FreeBSD_version < 500034
     struct  timecounter *tc;
     u_int   count;
+#endif
+#endif
 
     int_ctl = read_vuart_port(UART_IER);
     int_ctl_new = int_ctl;
 
     while (!com->gone) {
+#ifdef ENABLE_PPS
         if (com->pps.ppsparam.mode & PPS_CAPTUREBOTH) {
             modem_status = read_vuart_port(UART_MSR);
             if ((modem_status ^ com->last_modem_status) & MSR_DCD) {
+#if __FreeBSD_version < 500034
                 tc = timecounter;
                 count = tc->tc_get_timecount(tc);
                 pps_event(&com->pps, tc, count, 
+#else
+                pps_capture(&com->pps);
+                pps_event(&com->pps,
+#endif
                           (modem_status & MSR_DCD) ? 
                           PPS_CAPTUREASSERT : PPS_CAPTURECLEAR);
             }
         }
+#endif
         line_status = read_vuart_port(UART_LSR);
 
         /* input event? (check first to help avoid overruns) */
@@ -1948,7 +2064,11 @@
                     recv_data = 0;
             }
             ++com->bytes_in;
+#if __FreeBSD_version > 502118
+            if (com->tp->t_hotchar != 0 && recv_data == com->tp->t_hotchar)
+#else
             if (com->hotchar != 0 && recv_data == com->hotchar)
+#endif
                 setsofttty();
             ioptr = com->iptr;
             if (ioptr >= com->ibufend)
@@ -2053,7 +2173,11 @@
 }
 
 static int
+#if __FreeBSD_version > 502115
+sioioctl(struct cdev *dev, u_long cmd, caddr_t data, int flag, struct proc *p)
+#else
 sioioctl(dev_t dev, u_long cmd, caddr_t data, int flag, struct proc *p)
+#endif
 {
     struct com_s    *com;
     int     error;
@@ -2134,7 +2258,11 @@
         if (lt->c_ospeed != 0)
             dt->c_ospeed = tp->t_ospeed;
     }
+#if __FreeBSD_version > 502112
+    error = (*linesw[tp->t_line]->l_ioctl)(tp, cmd, data, flag, p);
+#else
     error = (*linesw[tp->t_line].l_ioctl)(tp, cmd, data, flag, p);
+#endif
     if (error != ENOIOCTL)
         return (error);
     s = splfunc();
@@ -2189,13 +2317,17 @@
         com->do_timestamp = TRUE;
         *(struct timeval *)data = com->timestamp;
         break;
+#if __FreeBSD_version < 502119
     case TIOCDCDTIMESTAMP:
         com->do_dcd_timestamp = TRUE;
         *(struct timeval *)data = com->dcd_timestamp;
         break;
+#endif
     default:
         splx(s);
+#ifdef ENABLE_PPS
         error = pps_ioctl(cmd, data, &com->pps);
+#endif
         if (error == ENODEV)
             error = ENOTTY;
         return (error);
@@ -2257,8 +2389,13 @@
             com->state &= ~CS_CHECKMSR;
             lt_enable_intr();
             if (delta_modem_status & MSR_DCD)
+#if __FreeBSD_version > 502112
+                (*linesw[tp->t_line]->l_modem)
+                    (tp, com->prev_modem_status & MSR_DCD);
+#else
                 (*linesw[tp->t_line].l_modem)
                     (tp, com->prev_modem_status & MSR_DCD);
+#endif
         }
         if (com->state & CS_ODONE) {
             lt_disable_intr();
@@ -2270,7 +2407,11 @@
                 sio_busycheck_handle = timeout(siobusycheck, com, hz / 100);
                 com->extra_state |= CSE_BUSYCHECK;
             }
+#if __FreeBSD_version > 502112
+            (*linesw[tp->t_line]->l_start)(tp);
+#else
             (*linesw[tp->t_line].l_start)(tp);
+#endif
         }
         if (com_events == 0)
             break;
@@ -2769,11 +2910,21 @@
         && (!(t->c_iflag & PARMRK)
         || (t->c_iflag & (IGNPAR | IGNBRK)) == (IGNPAR | IGNBRK))
         && !(t->c_lflag & (ECHO | ICANON | IEXTEN | ISIG | PENDIN))
+#if __FreeBSD_version > 502112
+        && linesw[tp->t_line]->l_rint == ttyinput)
+#else
         && linesw[tp->t_line].l_rint == ttyinput)
+#endif
         tp->t_state |= TS_CAN_BYPASS_L_RINT;
     else
         tp->t_state &= ~TS_CAN_BYPASS_L_RINT;
+#if __FreeBSD_version > 502112
+#if __FreeBSD_version < 502119
+    com->hotchar = linesw[tp->t_line]->l_hotchar;
+#endif
+#else
     com->hotchar = linesw[tp->t_line].l_hotchar;
+#endif
 }
 
 #ifdef KLD_MODULE
@@ -2796,7 +2947,7 @@
 #endif
 
 DRIVER_MODULE(ltmdm, pci, ltmdm_pci_driver, ltmdm_devclass, ltmdm_event, 0);
-#if 0
+#if 1
 #if __FreeBSD_version >= 500000
 DRIVER_MODULE(ltmdm, cardbus, ltmdm_pci_driver, ltmdm_devclass, ltmdm_event, 0);
 #endif
