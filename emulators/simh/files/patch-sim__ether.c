--- sim_ether.c.orig	2016-12-01 22:43:43 UTC
+++ sim_ether.c
@@ -1333,7 +1333,7 @@ static void eth_get_nic_hw_addr(ETH_DEV*
     for (i=0; patterns[i] && (0 == dev->have_host_nic_phy_addr); ++i) {
       snprintf(command, sizeof(command)-1, "ifconfig %s | %s  >NIC.hwaddr", devname, patterns[i]);
       system(command);
-      if (f = fopen("NIC.hwaddr", "r")) {
+      if ((f = fopen("NIC.hwaddr", "r"))) {
         while (0 == dev->have_host_nic_phy_addr) {
           if (fgets(command, sizeof(command)-1, f)) {
             char *p1, *p2;
@@ -1519,7 +1519,7 @@ sim_debug(dev->dbit, dev->dptr, "Writer 
 pthread_mutex_lock (&dev->writer_lock);
 while (dev->handle) {
   pthread_cond_wait (&dev->writer_cond, &dev->writer_lock);
-  while (request = dev->write_requests) {
+  while ((request = dev->write_requests)) {
     /* Pull buffer off request list */
     dev->write_requests = request->next;
     pthread_mutex_unlock (&dev->writer_lock);
@@ -1827,11 +1827,11 @@ pthread_mutex_destroy (&dev->writer_lock
 pthread_cond_destroy (&dev->writer_cond);
 if (1) {
   struct write_request *buffer;
-   while (buffer = dev->write_buffers) {
+   while ((buffer = dev->write_buffers)) {
     dev->write_buffers = buffer->next;
     free(buffer);
     }
-  while (buffer = dev->write_requests) {
+  while ((buffer = dev->write_requests)) {
     dev->write_requests = buffer->next;
     free(buffer);
     }
@@ -2084,7 +2084,7 @@ if (!dev) return SCPE_UNATT;
 
 /* Get a buffer */
 pthread_mutex_lock (&dev->writer_lock);
-if (request = dev->write_buffers)
+if ((request = dev->write_buffers))
   dev->write_buffers = request->next;
 pthread_mutex_unlock (&dev->writer_lock);
 if (!request)
