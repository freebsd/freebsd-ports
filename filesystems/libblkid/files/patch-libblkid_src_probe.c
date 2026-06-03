--- libblkid/src/probe.c.orig	2025-06-24 07:55:28 UTC
+++ libblkid/src/probe.c
@@ -594,7 +594,18 @@ static struct blkid_bufinfo *read_buffer(blkid_probe p
 	DBG(LOWPROBE, ul_debug("\tread: off=%"PRIu64" len=%"PRIu64"",
 	                       real_off, len));
 
-	ret = read(pr->fd, bf->data, len);
+	/* on FreeBSD, devices are unbuffered so we need to align to full I/O blocks by ourselves */
+	if (len % pr->io_size) {
+		unsigned rawlen = len + (pr->io_size - len % pr->io_size);
+		char buf[rawlen];
+		ret = read(pr->fd, buf, rawlen);
+		if (ret < 0 || ret < len)
+			return NULL;
+		memcpy(bf->data, buf, len);
+		ret = len;
+	} else {
+		ret = read(pr->fd, bf->data, len);
+	}
 	if (ret != (ssize_t) len) {
 		DBG(LOWPROBE, ul_debug("\tread failed: %m"));
 		remove_buffer(bf);
@@ -718,7 +729,7 @@ const unsigned char *blkid_probe_get_buffer(blkid_prob
 	struct blkid_bufinfo *bf = NULL;
 	uint64_t real_off, bias, len_align;
 
-	bias = off % pr->io_size;
+	bias = off % /* pr->io_size */ 4096;
 	off -= bias;
 	len += bias;
 
@@ -1106,6 +1117,7 @@ int blkid_probe_set_device(blkid_probe pr, int fd,
 			goto err;
 		}
 	} else if (S_ISCHR(sb.st_mode)) {
+#ifdef __linux__
 		char buf[PATH_MAX];
 
 		if (!sysfs_chrdev_devno_to_devname(sb.st_rdev, buf, sizeof(buf))
@@ -1114,6 +1126,9 @@ int blkid_probe_set_device(blkid_probe pr, int fd,
 			errno = EINVAL;
 			goto err;
 		}
+#else
+		/* no-op, FreeBSD maps block devices as character */
+#endif
 		devsiz = 1;		/* UBI devices are char... */
 	} else if (S_ISREG(sb.st_mode))
 		devsiz = sb.st_size;	/* regular file */
