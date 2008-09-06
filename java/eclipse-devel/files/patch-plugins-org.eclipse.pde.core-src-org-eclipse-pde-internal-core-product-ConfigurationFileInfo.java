--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/ConfigurationFileInfo.java.orig	2008-08-02 17:18:07.000000000 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/ConfigurationFileInfo.java	2008-08-02 17:32:35.000000000 -0400
@@ -25,11 +25,13 @@
 	private String fPath;
 
 	private static final String LIN = Constants.OS_LINUX;
+	private static final String FRE = Constants.OS_FREEBSD;
 	private static final String MAC = Constants.OS_MACOSX;
 	private static final String SOL = Constants.OS_SOLARIS;
 	private static final String WIN = Constants.OS_WIN32;
 
 	private String fLinPath, fLinUse;
+	private String fFrePath, fFreUse;
 	private String fMacPath, fMacUse;
 	private String fSolPath, fSolUse;
 	private String fWinPath, fWinUse;
@@ -70,6 +72,9 @@
 					if (child.getNodeName().equals(LIN)) {
 						fLinPath = getText(child);
 						fLinUse = fLinPath == null ? "default" : "custom"; //$NON-NLS-1$ //$NON-NLS-2$
+					} else if (child.getNodeName().equals(FRE)) {
+						fFrePath = getText(child);
+						fFreUse = fFrePath == null ? "default" : "custom"; //$NON-NLS-1$ //$NON-NLS-2$
 					} else if (child.getNodeName().equals(MAC)) {
 						fMacPath = getText(child);
 						fMacUse = fMacPath == null ? "default" : "custom"; //$NON-NLS-1$ //$NON-NLS-2$
@@ -89,6 +94,10 @@
 					fLinPath = fLinPath == null ? fPath : null;
 					fLinUse = "custom"; //$NON-NLS-1$
 				}
+				if (fFreUse == null) {
+					fFrePath = fFreUse == null ? fPath : null;
+					fFreUse = "custom"; //$NON-NLS-1$
+				}
 				if (fMacUse == null) {
 					fMacPath = fMacPath == null ? fPath : null;
 					fMacUse = "custom"; //$NON-NLS-1$
@@ -139,6 +148,12 @@
 			writer.println("</" + LIN + ">"); //$NON-NLS-1$ //$NON-NLS-2$
 		}
 
+                if (fFrePath != null) {
+                        writer.print(indent);
+                        writer.print("   <" + FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$
+                        writer.print(getWritableString(fFrePath.trim()));
+                        writer.println("</" + FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$
+                }
 		if (fMacPath != null) {
 			writer.print(indent);
 			writer.print("   <" + MAC + ">"); //$NON-NLS-1$ //$NON-NLS-2$
@@ -182,6 +197,11 @@
 			fLinUse = use;
 			if (isEditable())
 				firePropertyChanged(LIN, old, fLinUse);
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			String old = fFreUse;
+			fFreUse = use;
+			if (isEditable())
+				firePropertyChanged(FRE, old, fFreUse);
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			String old = fMacUse;
 			fMacUse = use;
@@ -203,6 +223,8 @@
 			return fWinUse;
 		} else if (Platform.OS_LINUX.equals(os)) {
 			return fLinUse;
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			return fFreUse;
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			return fMacUse;
 		} else if (Platform.OS_SOLARIS.equals(os)) {
@@ -229,6 +251,11 @@
 			fLinPath = path;
 			if (isEditable())
 				firePropertyChanged(LIN, old, fLinPath);
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			String old = fFrePath;
+			fFrePath = path;
+			if (isEditable())
+				firePropertyChanged(FRE, old, fFrePath);
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			String old = fMacPath;
 			fMacPath = path;
@@ -250,6 +277,8 @@
 			return fWinPath;
 		} else if (Platform.OS_LINUX.equals(os)) {
 			return fLinPath;
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			return fFrePath;
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			return fMacPath;
 		} else if (Platform.OS_SOLARIS.equals(os)) {
