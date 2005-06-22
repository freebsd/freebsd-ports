--- sys/dev/ltmdm/ltmdmsio.c.orig	Mon Mar 11 18:47:31 2002
+++ sys/dev/ltmdm/ltmdmsio.c	Wed Jun 22 13:06:35 2005
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
@@ -124,10 +137,15 @@
 #endif
 
 #if __FreeBSD_version >= 500023 /* >= 20010912 */
-#define proc thread         /* temporary hack: struct proc -> stuct thread */
+#define proc thread         /* XXX  struct proc -> stuct thread */
+#if __FreeBSD_version <  500033 /* <  20020401 */
 #define suser(p) suser_td(p)
 #endif
+#endif
 
+#ifndef PCI_BAR
+#define PCI_BAR(x) PCI_MAPS + (x) * 4
+#endif
 
 #define LOTS_OF_EVENTS  64  /* helps separate urgent events from input */
 
@@ -230,7 +248,9 @@
     u_char  last_modem_status;  /* last MSR read by intr handler */
     u_char  prev_modem_status;  /* last MSR handled by high level */
 
+#if __FreeBSD_version < 502119
     u_char  hotchar;        /* ldisc-specific char to be handled ASAP */
+#endif
     u_char  *ibuf;          /* start of input buffer */
     u_char  *ibufend;       /* end of input buffer */
     u_char  *ibufold;       /* old input buffer, to be freed */
@@ -256,7 +276,9 @@
     bool_t  do_dcd_timestamp;
     struct timeval  timestamp;
     struct timeval  dcd_timestamp;
+#ifdef ENABLE_PPS
     struct  pps_state pps;
+#endif
 
     u_long  bytes_in;       /* statistics */
     u_long  bytes_out;
@@ -268,7 +290,11 @@
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
@@ -352,6 +378,7 @@
 #endif
 
 static struct cdevsw sio_cdevsw = {
+#if __FreeBSD_version < 500105
     /* open */  sioopen,
     /* close */ sioclose,
     /* read */  sioread,
@@ -361,7 +388,11 @@
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
@@ -373,10 +404,32 @@
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
+#if __FreeBSD_version < 600019
+#ifdef MAJOR_AUTO
+    .d_maj = MAJOR_AUTO,
+#else
+    .d_maj = CDEV_MAJOR,
+#endif
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
@@ -566,8 +619,8 @@
 u_int32_t Get_PCI_BASE_ADDRESS_IO_MASK(void);
 u_int8_t  Get_PCI_BASE_ADDRESS_SPACE_IO(void);
 u_int32_t VMODEM_Get_System_Time(void);
-u_int8_t  inp(u_int16_t addr);
-void      outp(u_int16_t addr, u_int8_t value);
+u_char    inp(u_int addr);
+void      outp(u_int addr, u_char value);
 u_int16_t inpw(u_int16_t addr);
 void      outpw(u_int16_t addr, u_int16_t value);
 u_int32_t inpd(u_int16_t addr);
@@ -695,7 +748,7 @@
 
         for (i = 0; i < 6; i++) {
             dev_info->BaseAddress[i]
-                    = pci_read_config(lt_dev, PCIR_MAPS + i * 4, 4);
+                    = pci_read_config(lt_dev, PCIR_BAR(i), 4);
             DPRINTF(1,("    BaseAddress[%d] = 0x%08lx\n",
                        i, dev_info->BaseAddress[i]));
         }
@@ -836,12 +889,12 @@
     return t;
 }
 
-u_int8_t inp(u_int16_t addr)
+u_char inp(u_int addr)
 {
     return inb(addr);
 }
 
-void outp(u_int16_t addr, u_int8_t value)
+void outp(u_int addr, u_char value)
 {
     outb(addr, value);
 }
@@ -968,8 +1021,6 @@
 {
     {   SWI_TTY     ,   "SWI_TTY"       },
     {   SWI_NET     ,   "SWI_NET"       },
-    {   SWI_CAMNET  ,   "SWI_CAMNET"    },
-    {   SWI_CAMBIO  ,   "SWI_CAMBIO"    },
     {   -1          ,   NULL            }
 };
 
@@ -1175,7 +1226,7 @@
 
     found = 0;
     for (i = 0; i < 6; i++) {
-        com->iorid[i] = PCIR_MAPS + 4 * i;
+        com->iorid[i] = PCIR_BAR(i);
         data = pci_read_config(dev, com->iorid[i], 4);
         if (((data &  0x01UL) == 0x01) &&
             ((data & ~0x03UL) != 0   )) {
@@ -1295,8 +1346,11 @@
     DPRINTF(1,("  x_chip_version    = %d\n", x_chip_version));
 
     com->flags = flags;
+
+#ifdef ENABLE_PPS
     com->pps.ppscap = PPS_CAPTUREASSERT | PPS_CAPTURECLEAR;
     pps_init(&com->pps);
+#endif
 
     /*
      * initialize the device registers as follows:
@@ -1433,11 +1487,19 @@
 
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
@@ -1470,7 +1532,11 @@
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
@@ -1610,7 +1676,11 @@
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
@@ -1626,7 +1696,11 @@
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
@@ -1639,7 +1713,11 @@
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
@@ -1654,11 +1732,19 @@
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
@@ -1685,7 +1771,9 @@
     s = splfunc();
     com->do_timestamp = FALSE;
     com->do_dcd_timestamp = FALSE;
+#ifdef ENABLE_PPS
     com->pps.ppsparam.mode = 0;
+#endif
     write_vuart_port(UART_CFCR, com->cfcr_image &= ~CFCR_SBREAK);
     {
         write_vuart_port(UART_IER, 0);
@@ -1724,7 +1812,11 @@
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
@@ -1735,11 +1827,19 @@
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
@@ -1754,7 +1854,11 @@
     if (com == NULL || com->gone)
         return (ENODEV);
 
+#if __FreeBSD_version > 502112
+    return ((*linesw[com->tp->t_line]->l_write)(com->tp, uio, flag));
+#else
     return ((*linesw[com->tp->t_line].l_write)(com->tp, uio, flag));
+#endif
 }
 
 static void
@@ -1860,7 +1964,11 @@
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
@@ -1894,23 +2002,34 @@
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
@@ -1948,7 +2067,11 @@
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
@@ -2053,7 +2176,11 @@
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
@@ -2134,7 +2261,11 @@
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
@@ -2189,13 +2320,17 @@
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
@@ -2257,8 +2392,13 @@
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
@@ -2270,7 +2410,11 @@
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
@@ -2769,11 +2913,21 @@
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
@@ -2796,7 +2950,7 @@
 #endif
 
 DRIVER_MODULE(ltmdm, pci, ltmdm_pci_driver, ltmdm_devclass, ltmdm_event, 0);
-#if 0
+#if 1
 #if __FreeBSD_version >= 500000
 DRIVER_MODULE(ltmdm, cardbus, ltmdm_pci_driver, ltmdm_devclass, ltmdm_event, 0);
 #endif
