--- plugins/org.eclipse.update.core/src/org/eclipse/update/internal/core/UpdateManagerUtils.java.orig	Thu Mar  6 14:43:57 2003
+++ plugins/org.eclipse.update.core/src/org/eclipse/update/internal/core/UpdateManagerUtils.java	Thu Mar  6 14:44:53 2003
@@ -17,7 +17,7 @@
  */
 public class UpdateManagerUtils {
 
-	private static boolean OS_UNIX = BootLoader.OS_HPUX.equals(BootLoader.getOS()) || BootLoader.OS_AIX.equals(BootLoader.getOS()) || BootLoader.OS_LINUX.equals(BootLoader.getOS()) || BootLoader.OS_SOLARIS.equals(BootLoader.getOS());
+	private static boolean OS_UNIX = BootLoader.OS_HPUX.equals(BootLoader.getOS()) || BootLoader.OS_AIX.equals(BootLoader.getOS()) || BootLoader.OS_LINUX.equals(BootLoader.getOS()) || BootLoader.OS_FREEBSD.equals(BootLoader.getOS()) || BootLoader.OS_SOLARIS.equals(BootLoader.getOS());
 
 	private static Map table;
 
@@ -735,4 +735,4 @@
 		writer.init(file,encoding);
 		return writer;
 	}
-}
\ No newline at end of file
+}
