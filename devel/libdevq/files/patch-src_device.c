From 7b48b8726b85eac66c1b164fab87d154be5aa068 Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?Jean-S=C3=A9bastien=20P=C3=A9dron?= <dumbbell@FreeBSD.org>
Date: Fri, 13 Feb 2015 19:46:37 +0100
Subject: [PATCH] Support dev.$driver.$n.%location from FreeBSD 11.x

The format changed from:
    slot=1 function=0
to:
    pci0:2:0:0 handle=\_SB_.PCI0.PEG3.MXM3

Now devq_device_get_pciid_from_fd() supports both formats.
---
 src/device.c | 89 ++++++++++++++++++++++++++++++++++++++++--------------------
 1 file changed, 60 insertions(+), 29 deletions(-)

diff --git a/src/device.c b/src/device.c
index 9aadc2b..77df580 100644
--- src/device.c
+++ src/device.c
@@ -188,6 +188,58 @@ devq_device_get_devpath_from_fd(int fd,
 #endif /* defined(HAVE_LIBPROCSTAT_H) */
 }
 
+static int
+devq_compare_vgapci_busaddr(int i, int *domain, int *bus, int *slot,
+    int *function)
+{
+	int ret;
+	char sysctl_name[32], sysctl_value[128];
+	size_t sysctl_value_len;
+
+	sprintf(sysctl_name, "dev.vgapci.%d.%%location", i);
+
+	sysctl_value_len = sizeof(sysctl_value);
+	memset(sysctl_value, 0, sysctl_value_len);
+	ret = sysctlbyname(sysctl_name, sysctl_value,
+	    &sysctl_value_len, NULL, 0);
+	if (ret != 0)
+		return (-1);
+
+	/*
+	 * dev.vgapci.$m.%location can have two formats:
+	 *     o  "pci0:2:0:0 handle=\_SB_.PCI0.PEG3.MXM3" (FreeBSD 11+)
+	 *     o  "slot=1 function=0" (up-to FreeBSD 10)
+	 */
+
+	ret = sscanf(sysctl_value, "pci%d:%d:%d:%d %*s",
+	    domain, bus, slot, function);
+	if (ret == 4)
+		return (0);
+
+	ret = sscanf(sysctl_value, "slot=%d function=%d %*s",
+	    slot, function);
+	if (ret != 2)
+		return (-1);
+
+	sprintf(sysctl_name, "dev.vgapci.%d.%%parent", i);
+
+	sysctl_value_len = sizeof(sysctl_value);
+	memset(sysctl_value, 0, sysctl_value_len);
+	ret = sysctlbyname(sysctl_name, sysctl_value,
+	    &sysctl_value_len, NULL, 0);
+	if (ret != 0)
+		return (-1);
+
+	ret = sscanf(sysctl_value, "pci%d", bus);
+	if (ret != 1)
+		return (-1);
+
+	/* FIXME: What domain to assume? */
+	*domain = 0;
+
+	return (0);
+}
+
 int
 devq_device_get_pciid_from_fd(int fd,
     int *vendor_id, int *device_id)
@@ -253,38 +305,17 @@ devq_device_get_pciid_from_fd(int fd,
 	 *     o  dev.vgapci.$m.%parent
 	 */
 	for (i = 0; i < DEVQ_MAX_DEVS; ++i) {
-		sprintf(sysctl_name, "dev.vgapci.%d.%%location", i);
-
-		sysctl_value_len = sizeof(sysctl_value);
-		memset(sysctl_value, 0, sysctl_value_len);
-		ret = sysctlbyname(sysctl_name, sysctl_value,
-		    &sysctl_value_len, NULL, 0);
-		if (ret != 0)
-			continue;
+		int tmp_domain, tmp_bus, tmp_slot, tmp_function;
 
-		int tmp_slot, tmp_function;
-		ret = sscanf(sysctl_value, "slot=%d function=%d %*s",
+		ret = devq_compare_vgapci_busaddr(i, &tmp_domain, &tmp_bus,
 		    &tmp_slot, &tmp_function);
-		if (ret != 2 ||
-		    tmp_slot != slot || tmp_function != function)
-			continue;
-
-		sprintf(sysctl_name, "dev.vgapci.%d.%%parent", i);
-
-		sysctl_value_len = sizeof(sysctl_value);
-		memset(sysctl_value, 0, sysctl_value_len);
-		ret = sysctlbyname(sysctl_name, sysctl_value,
-		    &sysctl_value_len, NULL, 0);
-		if (ret != 0)
-			continue;
-
-		int tmp_bus;
-		ret = sscanf(sysctl_value, "pci%d",
-		    &tmp_bus);
-		if (ret != 1 || tmp_bus != bus)
-			continue;
 
-		break;
+		if (ret == 0 &&
+		    tmp_domain == domain &&
+		    tmp_bus == bus &&
+		    tmp_slot == slot &&
+		    tmp_function == function)
+			break;
 	}
 
 	if (i == DEVQ_MAX_DEVS) {
