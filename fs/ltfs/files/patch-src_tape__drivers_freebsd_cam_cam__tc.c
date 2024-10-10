--- src/tape_drivers/freebsd/cam/cam_tc.c.orig	2023-09-17 04:20:07 UTC
+++ src/tape_drivers/freebsd/cam/cam_tc.c
@@ -1241,7 +1241,7 @@ static int camtape_get_next_block_to_xfer(void *device
 		camtape_process_errors(softc, rc, msg, "READPOS", true);
 	else {
 		pos->partition = ext_data.partition;
-		pos->block = scsi_8btou64(ext_data.last_object)
+		pos->block = scsi_8btou64(ext_data.last_object);
 		ltfsmsg(LTFS_DEBUG, 30398D, "next-block-to-xfer",
 				(unsigned long long) pos->block, 0, 0, softc->drive_serial);
 	}
