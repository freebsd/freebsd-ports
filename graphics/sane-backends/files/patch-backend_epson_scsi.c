--- backend/epson_scsi.c.orig	Sun Apr 27 21:57:39 2003
+++ backend/epson_scsi.c	Tue Aug 12 14:26:20 2003
@@ -93,15 +93,16 @@
 {
 	u_char * cmd;
 
-	cmd = alloca( 6 + buf_size);
-	memset( cmd, 0, 6);
+#define	ALIGN	8
+	cmd = alloca( ALIGN + buf_size);
+	memset( cmd, 0, ALIGN);
 	cmd[ 0] = WRITE_6_COMMAND;
 	cmd[ 2] = buf_size >> 16;
 	cmd[ 3] = buf_size >> 8;
 	cmd[ 4] = buf_size;
-	memcpy( cmd + 6, buf, buf_size);
+	memcpy( cmd + ALIGN, buf, buf_size);
 
-	if( SANE_STATUS_GOOD == ( *status = sanei_scsi_cmd( fd, cmd, 6 + buf_size, NULL, NULL)))
+	if( SANE_STATUS_GOOD == ( *status = sanei_scsi_cmd2( fd, cmd, 6, cmd + ALIGN, buf_size, NULL, NULL)))
 		return buf_size;
 
 	return 0;
