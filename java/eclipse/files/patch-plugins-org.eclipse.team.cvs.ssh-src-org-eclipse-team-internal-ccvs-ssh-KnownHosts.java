--- plugins/org.eclipse.team.cvs.ssh/src/org/eclipse/team/internal/ccvs/ssh/KnownHosts.java.orig	2008-08-02 23:18:54.457655000 -0400
+++ plugins/org.eclipse.team.cvs.ssh/src/org/eclipse/team/internal/ccvs/ssh/KnownHosts.java	2008-08-02 23:20:58.798422053 -0400
@@ -38,7 +38,8 @@
 	}
 	
 	static String defaultFilename() {
-		if (!Platform.getOS().equals(Platform.OS_LINUX)) return internalFilename();
+		if (!Platform.getOS().equals(Platform.OS_LINUX) && !Platform.getOS().equals(Platform.OS_FREEBSD))
+			return internalFilename();
 		String HOME = System.getProperty("user.home"); //$NON-NLS-1$
 		if (HOME==null) return internalFilename();
 		return HOME+"/.ssh/known_hosts"; //$NON-NLS-1$
