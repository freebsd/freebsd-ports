--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/LauncherInfo.java.orig	2008-08-02 17:14:03.000000000 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/LauncherInfo.java	2008-08-02 17:17:11.000000000 -0400
@@ -76,6 +76,8 @@
 					String name = child.getNodeName();
 					if (name.equals("linux")) { //$NON-NLS-1$
 						parseLinux((Element) child);
+					} else if (name.equals("freebsd")) { //$NON-NLS-1$
+						parseFreeBSD((Element) child);
 					} else if (name.equals("macosx")) { //$NON-NLS-1$
 						parseMac((Element) child);
 					} else if (name.equals("solaris")) { //$NON-NLS-1$
@@ -124,6 +126,10 @@
 		fIcons.put(LINUX_ICON, element.getAttribute("icon")); //$NON-NLS-1$
 	}
 
+	public void parseFreeBSD(Element element) {
+		fIcons.put(FREEBSD_ICON, element.getAttribute("icon")); //$NON-NLS-1$
+	}
+
 	public void write(String indent, PrintWriter writer) {
 		writer.print(indent + "<launcher"); //$NON-NLS-1$
 		if (fLauncherName != null && fLauncherName.length() > 0)
@@ -131,6 +137,7 @@
 		writer.println(">"); //$NON-NLS-1$
 
 		writeLinux(indent + "   ", writer); //$NON-NLS-1$
+		writeFreeBSD(indent + "   ", writer); //$NON-NLS-1$
 		writeMac(indent + "   ", writer); //$NON-NLS-1$
 		writeSolaris(indent + "   ", writer); //$NON-NLS-1$
 		writerWin(indent + "   ", writer); //$NON-NLS-1$
@@ -183,4 +190,10 @@
 			writer.println(indent + "<linux icon=\"" + getWritableString(icon) + "\"/>"); //$NON-NLS-1$ //$NON-NLS-2$ 
 	}
 
+	private void writeFreeBSD(String indent, PrintWriter writer) {
+		String icon = (String) fIcons.get(FREEBSD_ICON);
+		if (icon != null && icon.length() > 0)
+			writer.println(indent + "<freebsd icon=\"" + getWritableString(icon) + "\"/>"); //$NON-NLS-1$ //$NON-NLS-2$
+	}
+
 }
