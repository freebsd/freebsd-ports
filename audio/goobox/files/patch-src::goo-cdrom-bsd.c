--- src/goo-cdrom-bsd.c.orig	Tue Nov  9 22:28:04 2004
+++ src/goo-cdrom-bsd.c	Thu Nov 11 12:19:49 2004
@@ -20,8 +20,6 @@
  *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
  */
 
-/* FIXME: this is only a template, BSD support lacks at the moment. */
-
 #include <config.h>
 
 #ifdef HAVE_BSD
@@ -30,9 +28,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
-#ifdef HAVE_SYS_CDIO_H
-# include <sys/cdio.h>
-#endif
+#include <sys/cdio.h>
 #include <errno.h>
 
 #include <gnome.h>
@@ -99,6 +95,7 @@
 
 	fd = open_device (cdrom);
 	if (fd >= 0) {
+		ioctl (fd, CDIOCALLOW, 0);
 		if (ioctl (fd, CDIOCEJECT, 0) >= 0) 
 			result = TRUE;
 		else 
@@ -112,52 +109,50 @@
 	return result;
 }
 
+static int msf = 1;
+static struct cd_toc_entry	toc_buffer[100];
+
+static int
+read_toc_entrys (int fd,
+		 int len)
+{
+	struct ioc_read_toc_entry t;
+
+	t.address_format = msf ? CD_MSF_FORMAT : CD_LBA_FORMAT;
+	t.starting_track = 0;
+	t.data_len = len;
+	t.data = toc_buffer;
+
+	return (ioctl (fd, CDIOREADTOCENTRYS, (char *) &t));
+}
+
 
 static int
 update_state_from_fd (GooCdrom *cdrom,
 		      int       fd)
 {
-	int           state;
-	GooCdromState cdrom_state;
+	int		      rc, i, n;
+	struct ioc_toc_header h;
 
-	state = ioctl (fd, CDROM_DISC_STATUS, 0);
-	if (state < 0) {
+	rc = ioctl (fd, CDIOREADTOCHEADER, &h);
+	if (rc < 0) {
 		goo_cdrom_set_error_from_string (cdrom, _("Error reading CD"));
 		return -1;
 	}
-	
-	switch (state) {
-	case CDS_NO_DISC:
-	case CDS_NO_INFO:
-		cdrom_state = GOO_CDROM_STATE_NO_DISC;
-		
-		state = ioctl (fd, CDROM_DRIVE_STATUS, CDSL_CURRENT);
-		if (state == -1) {
-			goo_cdrom_set_error_from_errno (cdrom);
-			return -1;
-		}
-		
-		switch (state) {
-		case CDS_TRAY_OPEN:
-			cdrom_state = GOO_CDROM_STATE_TRAY_OPEN;
-			break;
-		case CDS_DRIVE_NOT_READY:
-			cdrom_state = GOO_CDROM_STATE_DRIVE_NOT_READY;
-			break;
-		default:
-			break;
-		}
-		break;
-
-	case CDS_AUDIO:
-		cdrom_state = GOO_CDROM_STATE_OK;
-		break;
-	default:
-		cdrom_state = GOO_CDROM_STATE_DATA_CD;
-		break;
+
+	n = h.ending_track - h.starting_track + 1;
+	rc = read_toc_entrys (fd, (n + 1) * sizeof (struct cd_toc_entry));
+	if (rc < 0) {
+		goo_cdrom_set_error_from_errno (cdrom);
+		return -1;
+	}
+
+	for (i = 0; i < n; i++) {
+		if (!(toc_buffer[i].control & 4))
+			return GOO_CDROM_STATE_OK;
 	}
 
-	return cdrom_state;
+	return GOO_CDROM_STATE_DATA_CD;
 }
 
 
@@ -173,6 +168,7 @@
 	if (fd >= 0) {
 		GooCdromState new_state = -1;
 
+		ioctl (fd, CDIOCALLOW, 0);
 		if (ioctl (fd, CDIOCCLOSE, 0) >= 0) {
 			new_state = update_state_from_fd (cdrom, fd);
 			result = (new_state != -1);
@@ -202,9 +198,10 @@
 
 	fd = open_device (cdrom);
 	if (fd >= 0) {
+		unsigned long cmd = lock ? CDIOCPREVENT : CDIOCALLOW;
 		GooCdromState new_state = -1;
 
-		if (ioctl (fd, CDROM_LOCKDOOR, lock) >= 0) { /*FIXME*/
+		if (ioctl (fd, cmd) != -1) {
 			new_state = update_state_from_fd (cdrom, fd);
 			result = (new_state != -1);
 		} else 
