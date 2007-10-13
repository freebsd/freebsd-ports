--- plugins/org.eclipse.swt/Eclipse SWT PI/gtk/org/eclipse/swt/internal/gtk/OS.java.orig	2007-06-26 04:57:20.000000000 +0900
+++ plugins/org.eclipse.swt/Eclipse SWT PI/gtk/org/eclipse/swt/internal/gtk/OS.java	2007-09-12 13:29:42.000000000 +0900
@@ -23,18 +23,20 @@
 	}
 	
 	/** OS Constants */
-	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX;
+	public static final boolean IsFreeBSD, IsAIX, IsSunOS, IsLinux, IsHPUX;
 	static {
 		
 		/* Initialize the OS flags and locale constants */
 		String osName = System.getProperty ("os.name");
-		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false;
+		boolean isFreeBSD = false, isAIX = false, isSunOS = false, isLinux = false, isHPUX = false ;
+		if (osName.equals ("FreeBSD")) isFreeBSD = true;
 		if (osName.equals ("Linux")) isLinux = true;
 		if (osName.equals ("AIX")) isAIX = true;
 		if (osName.equals ("Solaris")) isSunOS = true;
 		if (osName.equals ("SunOS")) isSunOS = true;
 		if (osName.equals ("HP-UX")) isHPUX = true;
-		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsHPUX = isHPUX;
+		IsFreeBSD = isFreeBSD; IsAIX = isAIX;  IsSunOS = isSunOS;  
+                IsLinux = isLinux;  IsHPUX = isHPUX;
 	}
 
 	/** Constants */
