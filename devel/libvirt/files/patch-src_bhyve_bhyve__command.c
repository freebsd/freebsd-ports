--- src/bhyve/bhyve_command.c.orig	2018-02-26 09:02:18 UTC
+++ src/bhyve/bhyve_command.c
@@ -56,6 +56,12 @@ bhyveBuildNetArgStr(virConnectPtr conn,
     int ret = -1;
     virDomainNetType actualType = virDomainNetGetActualType(net);
 
+    if (net->model == NULL) {
+        virReportError(VIR_ERR_CONFIG_UNSUPPORTED, "%s",
+                       _("NIC model must be specified"));
+        return -1;
+    }
+
     if (STREQ(net->model, "virtio")) {
         if (VIR_STRDUP(nic_model, "virtio-net") < 0)
             return -1;
