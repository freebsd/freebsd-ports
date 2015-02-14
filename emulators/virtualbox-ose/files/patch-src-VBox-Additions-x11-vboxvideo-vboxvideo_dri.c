--- src/VBox/Additions/x11/vboxvideo/vboxvideo_dri.c.orig	2015-02-12 15:25:55.061952000 -0500
+++ src/VBox/Additions/x11/vboxvideo/vboxvideo_dri.c	2015-02-12 15:26:57.245403000 -0500
@@ -238,9 +238,11 @@
         pDRIInfo->TransitionTo2d = VBOXDRITransitionTo2d;
         pDRIInfo->TransitionTo3d = VBOXDRITransitionTo3d;
 
+#if defined(XORG_VERSION_CURRENT) && XORG_VERSION_CURRENT < 101700000
         /* These two are set in DRICreateInfoRec(). */
         pDRIInfo->wrap.ValidateTree = NULL;
         pDRIInfo->wrap.PostValidateTree = NULL;
+#endif
 
         pDRIInfo->drmDriverName = VBOX_DRM_DRIVER_NAME;
         pDRIInfo->clientDriverName = VBOX_DRI_DRIVER_NAME;
