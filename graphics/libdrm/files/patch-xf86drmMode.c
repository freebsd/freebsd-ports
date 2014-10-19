Disable checking for hw.dri.%d.modesetting.
This sysctl is only available if a KMS module is loaded. But the libdrm
check happens before X got a chance of loading the KMS module.

--- xf86drmMode.c.orig	2014-08-27 20:04:46.000000000 +0200
+++ xf86drmMode.c	2014-10-18 15:12:02.586937600 +0200
@@ -774,38 +774,7 @@
 	if (found)
 		return 0;
 #elif defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
-	char kbusid[1024], sbusid[1024];
-	char oid[128];
-	int domain, bus, dev, func;
-	int i, modesetting, ret;
-	size_t len;
-
-	ret = sscanf(busid, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev,
-	    &func);
-	if (ret != 4)
-		return -EINVAL;
-	snprintf(kbusid, sizeof(kbusid), "pci:%04x:%02x:%02x.%d", domain, bus,
-	    dev, func);
-
-	/* How many GPUs do we expect in the machine ? */
-	for (i = 0; i < 16; i++) {
-		snprintf(oid, sizeof(oid), "hw.dri.%d.busid", i);
-		len = sizeof(sbusid);
-		ret = sysctlbyname(oid, sbusid, &len, NULL, 0);
-		if (ret == -1) {
-			if (errno == ENOENT)
-				continue;
-			return -EINVAL;
-		}
-		if (strcmp(sbusid, kbusid) != 0)
-			continue;
-		snprintf(oid, sizeof(oid), "hw.dri.%d.modesetting", i);
-		len = sizeof(modesetting);
-		ret = sysctlbyname(oid, &modesetting, &len, NULL, 0);
-		if (ret == -1 || len != sizeof(modesetting))
-			return -EINVAL;
-		return (modesetting ? 0 : -ENOSYS);
-	}
+	return 0;
 #elif defined(__DragonFly__)
 	return 0;
 #endif
