--- src/bsd/link_gry.c.orig	Wed Oct 11 15:19:24 2006
+++ src/bsd/link_gry.c	Wed Oct 11 16:26:38 2006
@@ -51,10 +51,10 @@
 
 	switch(h->port)
 	{
-	case PORT_1: h->address = 0x3f8; h->device = strdup("/dev/cuaa0"); break;
-	case PORT_2: h->address = 0x2f8; h->device = strdup("/dev/cuaa1"); break;
-	case PORT_3: h->address = 0x3e8; h->device = strdup("/dev/cuaa2"); break;
-	case PORT_4: h->address = 0x3e8; h->device = strdup("/dev/cuaa3"); break;
+	case PORT_1: h->address = 0x3f8; h->device = strdup("/dev/cuad0"); break;
+	case PORT_2: h->address = 0x2f8; h->device = strdup("/dev/cuad1"); break;
+	case PORT_3: h->address = 0x3e8; h->device = strdup("/dev/cuad2"); break;
+	case PORT_4: h->address = 0x3e8; h->device = strdup("/dev/cuad3"); break;
 	default: return ERR_ILLEGAL_ARG;
 	}
 	h->priv2 = (struct termios *)calloc(1, sizeof(struct termios));
@@ -93,9 +93,15 @@
     termset->c_cflag = CS8 | CLOCAL | CREAD;
     termset->c_lflag = 0;
 #endif
+    termset->c_cc[VMIN] = 0;
+    termset->c_cc[VTIME] = h->timeout;
 
     cfsetispeed(termset, B9600);
     cfsetospeed(termset, B9600);
+    tcsetattr(dev_fd, TCSANOW, termset);
+
+    if(tcflush(dev_fd, TCIOFLUSH) == -1)
+        return ERR_FLUSH_ERROR;
 
     return 0;
 }
@@ -111,31 +117,18 @@
 
 static int gry_reset(CableHandle *h)
 {
-    uint8_t unused[1024];
-    int n;
-
-    /* Flush the input */
-    termset->c_cc[VMIN] = 0;
-    termset->c_cc[VTIME] = 0;
-    tcsetattr(dev_fd, TCSANOW, termset);
-    do
-    {
-	n = read(dev_fd, (void *) unused, 1024);
-    } while ((n != 0) && (n != -1));
-
-    /* and set/restore the timeout */
-    termset->c_cc[VTIME] = h->timeout;
-    tcsetattr(dev_fd, TCSANOW, termset);
+    if(tcflush(dev_fd, TCIOFLUSH) == -1)
+       return ERR_FLUSH_ERROR;
 
     return 0;
 }
 
 static int gry_put(CableHandle* h, uint8_t *data, uint32_t len)
 {
-    int err;
+    ssize_t ret;
 
-    err = write(dev_fd, (void *)data, len);
-    switch (err)
+    ret = write(dev_fd, (void *)data, len);
+    switch (ret)
     {
     case -1:		//error
 	return ERR_WRITE_ERROR;
@@ -150,19 +143,24 @@
 
 static int gry_get(CableHandle* h, uint8_t *data, uint32_t len)
 {
-    int err;
+    ssize_t ret;
+    ssize_t i;
 
     tcdrain(dev_fd);	// waits for all output written
 
-    err = read(dev_fd, (void *)data, len);
-    switch (err)
+    for(i = 0; i < len; )
     {
-    case -1:		//error
-	return ERR_READ_ERROR;
-    	break;
-    case 0:		// timeout
-	return ERR_READ_TIMEOUT;
-    	break;
+       ret = read(dev_fd, (void *)(data+i), len - i);
+       switch (ret)
+       {
+       case -1:                //error
+           return ERR_READ_ERROR;
+           break;
+       case 0:         // timeout
+           return ERR_READ_TIMEOUT;
+           break;
+       }
+       i += ret;
     }
 
     return 0;
