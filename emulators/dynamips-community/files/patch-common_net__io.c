--- common/net_io.c.orig	2016-03-16 09:05:47 UTC
+++ common/net_io.c
@@ -609,9 +609,11 @@ static int netio_tap_open(char *tap_devn
    return(fd);
 #else
    int i,fd = -1;
+   char tap_fullname[NETIO_DEV_MAXLEN];
    
    if (*tap_devname) {
-      fd = open(tap_devname,O_RDWR);
+      snprintf(tap_fullname,NETIO_DEV_MAXLEN,"/dev/%s",tap_devname);
+      fd = open(tap_fullname,O_RDWR);
    } else {
       for(i=0;i<16;i++) {
          snprintf(tap_devname,NETIO_DEV_MAXLEN,"/dev/tap%d",i);
