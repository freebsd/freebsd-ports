Fix for CVE-2014-8118 as found at
https://bugzilla.redhat.com/show_bug.cgi?id=1168715

--- lib/cpio.c.orig	2014-06-30 08:47:13 UTC
+++ lib/cpio.c
@@ -399,6 +399,9 @@ int rpmcpioHeaderRead(rpmcpio_t cpio, ch
 
     GET_NUM_FIELD(hdr.filesize, fsize);
     GET_NUM_FIELD(hdr.namesize, nameSize);
+    if (nameSize <= 0 || nameSize > 4096) {
+	return RPMERR_BAD_HEADER;
+    }
 
     char name[nameSize + 1];
     read = Fread(name, nameSize, 1, cpio->fd);
