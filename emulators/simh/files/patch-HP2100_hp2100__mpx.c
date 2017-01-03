--- HP2100/hp2100_mpx.c.orig	2016-12-01 22:43:42 UTC
+++ HP2100/hp2100_mpx.c
@@ -1153,7 +1153,7 @@ switch (mpx_cmd) {
     case CMD_REQ_WRITE:                                 /* request write buffer */
         port = key_to_port (mpx_portkey);               /* get port */
 
-        if (port >= 0)                                  /* port defined? */
+        if (port >= 0) {                                /* port defined? */
             if (buf_avail (iowrite, port) > 0)          /* is a buffer available? */
                 mpx_ibuf = WR_BUF_LIMIT;                /* report write buffer limit */
 
@@ -1161,6 +1161,7 @@ switch (mpx_cmd) {
                 mpx_ibuf = 0;                           /* report none available */
                 mpx_flags [port] |= FL_WANTBUF;         /* set buffer request */
                 }
+           }
         break;
 
 
@@ -1251,7 +1252,7 @@ switch (mpx_cmd) {
     case CMD_TERM_BUF:                                  /* terminate active receive buffer */
         port = key_to_port (mpx_portkey);               /* get port */
 
-        if (port >= 0)                                  /* port defined? */
+        if (port >= 0) {                                /* port defined? */
             if (buf_len (ioread, port, put) > 0) {      /* any chars in buffer? */
                 buf_term (ioread, port, 0);             /* terminate buffer and set header */
 
@@ -1263,6 +1264,7 @@ switch (mpx_cmd) {
                 mpx_charcnt [port] = 1;                 /* set to terminate on one char */
                 mpx_flags [port] |= FL_ALERT;           /* set alert flag */
                 }
+           }
         break;
 
 
@@ -1784,7 +1786,7 @@ while (recv_loop &&                     
         }
 
     else {                                                      /* buffer is available */
-        if (rt & RT_ENAB_EDIT)                                  /* editing enabled? */
+        if (rt & RT_ENAB_EDIT) {                                /* editing enabled? */
             if (ch == BS) {                                     /* backspace? */
                 if (buf_len (ioread, port, put) > 0)            /* at least one character in buffer? */
                     buf_remove (ioread, port);                  /* remove last char */
@@ -1814,6 +1816,7 @@ while (recv_loop &&                     
 
                 continue;
                 }
+        }
 
         if (uptr->flags & UNIT_CAPSLOCK)                    /* caps lock mode? */
             ch = toupper (ch);                              /* convert to upper case if lower */
@@ -2473,14 +2476,14 @@ else
 
 buf_incr (mpx_get, port, rw, +1);                       /* increment circular get index */
 
-if (DEBUG_PRI (mpx_dev, DEB_BUF))
+if (DEBUG_PRI (mpx_dev, DEB_BUF)) {
     if (mpx_flags [port] & emptying_flags [rw])
         fprintf (sim_deb, ">>MPX buf:  Port %d character %s get from %s buffer "
                           "[%d]\n", port, fmt_char (ch), io_op [rw], index);
     else
         fprintf (sim_deb, ">>MPX buf:  Port %d header %03o get from %s buffer "
                           "[%d]\n", port, ch, io_op [rw], index);
-
+    }
 if (mpx_get [port] [rw] == mpx_sep [port] [rw])         /* buffer now empty? */
     mpx_flags [port] &= ~emptying_flags [rw];           /* clear "buffer emptying" flag */
 else
