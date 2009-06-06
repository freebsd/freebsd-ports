--- plugins/org.eclipse.equinox.launcher/src/org/eclipse/equinox/launcher/Main.java.orig	2008-08-09 01:52:52.897300867 -0400
+++ plugins/org.eclipse.equinox.launcher/src/org/eclipse/equinox/launcher/Main.java	2008-08-09 01:53:31.527460286 -0400
@@ -291,6 +291,8 @@
 			return Constants.WS_WIN32;
 		if (osName.equals(Constants.OS_LINUX))
 			return Constants.WS_GTK;
+		if (osName.equals(Constants.OS_FREEBSD))
+			return Constants.WS_GTK;
 		if (osName.equals(Constants.OS_MACOSX))
 			return Constants.WS_CARBON;
 		if (osName.equals(Constants.OS_HPUX))
@@ -315,6 +317,8 @@
 			return Constants.OS_SOLARIS;
 		if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_LINUX))
 			return Constants.OS_LINUX;
+		if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_FREEBSD))
+			return Constants.OS_FREEBSD;
 		if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_QNX))
 			return Constants.OS_QNX;
 		if (osName.equalsIgnoreCase(Constants.INTERNAL_OS_AIX))
