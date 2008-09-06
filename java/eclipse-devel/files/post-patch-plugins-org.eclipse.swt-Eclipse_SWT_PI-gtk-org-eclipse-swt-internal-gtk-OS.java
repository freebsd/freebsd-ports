--- gtk/org/eclipse/swt/internal/gtk/OS.java.orig	2008-08-02 22:08:05.630890150 -0400
+++ gtk/org/eclipse/swt/internal/gtk/OS.java	2008-08-02 22:10:32.931793757 -0400
@@ -23,18 +23,19 @@
 	}
 	
 	/** OS Constants */
-	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX;
+	public static final boolean IsAIX, IsSunOS, IsLinux, IsFreeBSD, IsHPUX;
 	static {
 		
 		/* Initialize the OS flags and locale constants */
 		String osName = System.getProperty ("os.name");
-		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false;
+		boolean isAIX = false, isSunOS = false, isLinux = false, isFreeBSD = false, isHPUX = false;
 		if (osName.equals ("Linux")) isLinux = true;
+		if (osName.equals ("FreeBSD")) isFreeBSD = true;
 		if (osName.equals ("AIX")) isAIX = true;
 		if (osName.equals ("Solaris")) isSunOS = true;
 		if (osName.equals ("SunOS")) isSunOS = true;
 		if (osName.equals ("HP-UX")) isHPUX = true;
-		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsHPUX = isHPUX;
+		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsFreeBSD = isFreeBSD; IsHPUX = isHPUX;
 	}
 
 	/** Constants */
