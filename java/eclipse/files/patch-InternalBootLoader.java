--- plugins/org.eclipse.core.boot/src/org/eclipse/core/internal/boot/InternalBootLoader.java.orig	Thu Mar  6 12:17:11 2003
+++ plugins/org.eclipse.core.boot/src/org/eclipse/core/internal/boot/InternalBootLoader.java	Thu Mar  6 12:18:11 2003
@@ -946,6 +946,8 @@
 			ws = BootLoader.WS_WIN32;
 		else if (os.equals(BootLoader.OS_LINUX))
 			ws = BootLoader.WS_MOTIF;
+		else if (os.equals(BootLoader.OS_FREEBSD))
+			ws = BootLoader.WS_GTK;
 		else if (os.equals(BootLoader.OS_MACOSX))
 			ws = BootLoader.WS_CARBON;
 		else if (os.equals(BootLoader.OS_HPUX))
