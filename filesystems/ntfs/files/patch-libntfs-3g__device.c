--- libntfs-3g/device.c.orig	2022-10-20 15:33:44 UTC
+++ libntfs-3g/device.c
@@ -71,6 +71,10 @@
 #ifdef ENABLE_HD
 #include <hd.h>
 #endif
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <inttypes.h>
+#endif
 
 #include "types.h"
 #include "mst.h"
@@ -615,6 +619,39 @@ s64 ntfs_device_size_get(struct ntfs_device *dev, int 
 	return (low + 1LL) / block_size;
 }
 
+#ifdef __FreeBSD__
+off_t ntfs_device_partition_offset_get(struct ntfs_device *dev)
+{
+	char name[MAXPATHLEN], provider[MAXPATHLEN];
+	size_t conf_size;
+	char *conf, *line;
+	off_t offset;
+
+	if (sysctlbyname("kern.geom.conftxt", NULL, &conf_size, NULL, 0))
+		return -1;
+	conf = alloca(conf_size);
+	if (!conf)
+		return -1;
+	if (sysctlbyname("kern.geom.conftxt", conf, &conf_size, NULL, 0))
+		return -1;
+	if (dev->d_ops->ioctl(dev, DIOCGPROVIDERNAME, provider))
+		return -1;
+
+	while ((line = strsep(&conf, "\n"))) {
+		if (sscanf(line, "%*u PART %s %*llu %*u %*s %*u o %"
+		    SCNd64, name, &offset) != 2)
+			continue;
+		if (offset < 0 || strcmp(provider, name))
+			continue;
+		ntfs_log_debug("kern.geom.conftxt offset of PART %s is %"
+		    PRId64 " (0x%" PRIx64 ")\n", provider, offset, offset);
+		return offset;
+	}
+
+	return -1;
+}
+#endif
+
 /**
  * ntfs_device_partition_start_sector_get - get starting sector of a partition
  * @dev:	open device
@@ -642,6 +679,30 @@ s64 ntfs_device_partition_start_sector_get(struct ntfs
 			return geo.start;
 		}
 	}
+#elif defined(__FreeBSD__)
+	{
+		off_t offset;
+		int sect_size;
+
+		offset = ntfs_device_partition_offset_get(dev);
+		if (offset < 0) {
+			errno = EOPNOTSUPP;
+			return -1;
+		}
+		sect_size = ntfs_device_sector_size_get(dev);
+		if (sect_size <= 0) {
+			errno = EOPNOTSUPP;
+			return -1;
+		}
+		if (offset % sect_size) {
+			/* Invalid partition offset.
+			 * Not a multiple of the
+			 * logical sector size. */
+			errno = ERANGE;
+			return -1;
+		}
+		return offset / sect_size;
+	}
 #else
 	errno = EOPNOTSUPP;
 #endif
@@ -769,6 +830,22 @@ skip_hd:
 		}
 		err = errno;
 	}
+#elif defined(DIOCGFWSECTORS) && defined(DIOCGFWHEADS)
+	{
+		/* FreeBSD */
+		u_int sectors = 0, heads = 0;
+
+		if (!dev->d_ops->ioctl(dev, DIOCGFWSECTORS, &sectors) &&
+		    !dev->d_ops->ioctl(dev, DIOCGFWHEADS, &heads)) {
+			dev->d_heads = heads;
+			dev->d_sectors_per_track = sectors;
+			ntfs_log_debug("DIOCGFWSECTORS sectors per "
+					"track = %u\n", sectors);
+			ntfs_log_debug("DIOCGFWHEADSS heads = %u\n", heads);
+			return 0;
+		}
+		err = errno;
+	}
 #endif
 	errno = err;
 	return -1;
@@ -865,11 +942,11 @@ int ntfs_device_sector_size_get(struct ntfs_device *de
 #elif defined(DIOCGSECTORSIZE)
 	{
 		/* FreeBSD */
-		size_t sect_size = 0;
+		u_int sect_size = 0;
 
 		if (!dev->d_ops->ioctl(dev, DIOCGSECTORSIZE, &sect_size)) {
-			ntfs_log_debug("DIOCGSECTORSIZE sector size = %d bytes\n",
-					(int) sect_size);
+			ntfs_log_debug("DIOCGSECTORSIZE sector size = %u bytes\n",
+					sect_size);
 			return sect_size;
 		}
 	}
