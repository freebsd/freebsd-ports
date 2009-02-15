--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/exports/ProductExportOperation.java.orig	2008-08-02 16:56:58.000000000 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/exports/ProductExportOperation.java	2008-08-02 17:00:16.000000000 -0400
@@ -480,6 +480,8 @@
 				images = getSolarisImages(info);
 			} else if (os.equals("linux")) { //$NON-NLS-1$
 				images = getExpandedPath(info.getIconPath(ILauncherInfo.LINUX_ICON));
+			} else if (os.equals("freebsd")) { //$NON-NLS-1$
+				images = getExpandedPath(info.getIconPath(ILauncherInfo.FREEBSD_ICON));
 			} else if (os.equals("macosx")) { //$NON-NLS-1$
 				images = getExpandedPath(info.getIconPath(ILauncherInfo.MACOSX_ICON));
 			}
