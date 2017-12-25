Revert the following commit.

FreeBSD and DragonFly don't have the required render nodes.

-------

From 69a1b9959e59653da262185c4e2cf57d24939b19 Mon Sep 17 00:00:00 2001
From: Emil Velikov <emil.l.velikov@gmail.com>
Date: Mon, 29 Jun 2015 12:36:45 +0100
Subject: pipe-loader: drop support for non-render node devices

Render nodes have been around for quite some time. Removing support via
the master/primary node allows us to clean up the conditional
compilation and simplify the build greatly.

For example currently we the pipe-loader, which explicitly links against
xcb and friends (for X auth) if found at compile-time. That
would cause problems as one will be forced to use X/xcb, even if it's a
headless system that is used for opencl.

v2: Clarify the linking topic in the commit message.

Cc: Tom Stellard <thomas.stellard@amd.com>
Signed-off-by: Emil Velikov <emil.l.velikov@gmail.com>
Reviewed-by: Francisco Jerez <currojerez@riseup.net>


--- src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c.orig	2017-12-21 17:31:21 UTC
+++ src/gallium/auxiliary/pipe-loader/pipe_loader_drm.c
@@ -207,6 +207,14 @@ pipe_loader_drm_probe_fd(struct pipe_loa
 }
 
 static int
+open_drm_minor(int minor)
+{
+   char path[PATH_MAX];
+   snprintf(path, sizeof(path), DRM_DEV_NAME, DRM_DIR_NAME, minor);
+   return open(path, O_RDWR, 0);
+}
+
+static int
 open_drm_render_node_minor(int minor)
 {
    char path[PATH_MAX];
@@ -218,8 +226,15 @@ open_drm_render_node_minor(int minor)
 int
 pipe_loader_drm_probe(struct pipe_loader_device **devs, int ndev)
 {
-   int i, j, fd;
+   int i, k, fd, num_render_node_devs;
+   int j = 0;
+
+   struct {
+      unsigned vendor_id;
+      unsigned chip_id;
+   } render_node_devs[DRM_RENDER_NODE_MAX_NODES];
 
+   /* Look for render nodes first */
    for (i = DRM_RENDER_NODE_MIN_MINOR, j = 0;
         i <= DRM_RENDER_NODE_MAX_MINOR; i++) {
       struct pipe_loader_device *dev;
@@ -233,6 +248,9 @@ pipe_loader_drm_probe(struct pipe_loader
          continue;
       }
 
+      render_node_devs[j].vendor_id = dev->u.pci.vendor_id;
+      render_node_devs[j].chip_id = dev->u.pci.chip_id;
+
       if (j < ndev) {
          devs[j] = dev;
       } else {
@@ -242,6 +260,46 @@ pipe_loader_drm_probe(struct pipe_loader
       j++;
    }
 
+   num_render_node_devs = j;
+
+   /* Next look for drm devices. */
+   for (i = 0; i < DRM_MAX_MINOR; i++) {
+      struct pipe_loader_device *dev;
+      boolean duplicate = FALSE;
+      fd = open_drm_minor(i);
+      if (fd < 0)
+         continue;
+
+      if (!pipe_loader_drm_probe_fd(&dev, fd)) {
+         close(fd);
+         continue;
+      }
+
+      /* Check to make sure we aren't already accessing this device via
+       * render nodes.
+       */
+      for (k = 0; k < num_render_node_devs; k++) {
+         if (dev->u.pci.vendor_id == render_node_devs[k].vendor_id &&
+             dev->u.pci.chip_id == render_node_devs[k].chip_id) {
+            close(fd);
+            dev->ops->release(&dev);
+            duplicate = TRUE;
+            break;
+         }
+      }
+
+      if (duplicate)
+         continue;
+
+      if (j < ndev) {
+         devs[j] = dev;
+      } else {
+         dev->ops->release(&dev);
+      }
+
+      j++;
+   }
+
    return j;
 }
 
