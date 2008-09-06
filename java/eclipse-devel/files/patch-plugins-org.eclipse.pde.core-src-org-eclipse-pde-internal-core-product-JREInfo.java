--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/JREInfo.java.orig	2008-08-02 21:26:22.675516213 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/JREInfo.java	2008-08-02 21:26:09.925437642 -0400
@@ -23,12 +23,14 @@
 public class JREInfo extends ProductObject implements IJREInfo {
 
 	private static final String JRE_LIN = "linux"; //$NON-NLS-1$
+	private static final String JRE_FRE = "freebsd"; //$NON-NLS-1$
 	private static final String JRE_MAC = "macos"; //$NON-NLS-1$
 	private static final String JRE_SOL = "solaris"; //$NON-NLS-1$
 	private static final String JRE_WIN = "windows"; //$NON-NLS-1$
 
 	private static final long serialVersionUID = 1L;
 	private IPath fJVMLin;
+	private IPath fJVMFre;
 	private IPath fJVMMac;
 	private IPath fJVMSol;
 	private IPath fJVMWin;
@@ -45,6 +47,8 @@
 			return fJVMWin;
 		} else if (Platform.OS_LINUX.equals(os)) {
 			return fJVMLin;
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			return fJVMFre;
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			return fJVMMac;
 		} else if (Platform.OS_SOLARIS.equals(os)) {
@@ -67,6 +71,11 @@
 			fJVMLin = jreContainerPath;
 			if (isEditable())
 				firePropertyChanged(JRE_LIN, old, fJVMLin);
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			IPath old = fJVMFre;
+			fJVMFre = jreContainerPath;
+			if (isEditable())
+				firePropertyChanged(JRE_FRE, old, fJVMFre);
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			IPath old = fJVMMac;
 			fJVMMac = jreContainerPath;
@@ -104,6 +113,8 @@
 			if (child.getNodeType() == Node.ELEMENT_NODE) {
 				if (child.getNodeName().equals(JRE_LIN)) {
 					fJVMLin = getPath(child);
+				} else if (child.getNodeName().equals(JRE_FRE)) {
+					fJVMFre = getPath(child);
 				} else if (child.getNodeName().equals(JRE_MAC)) {
 					fJVMMac = getPath(child);
 				} else if (child.getNodeName().equals(JRE_SOL)) {
@@ -143,6 +154,12 @@
 			writer.print(fJVMLin.toPortableString());
 			writer.println("</" + JRE_LIN + ">"); //$NON-NLS-1$ //$NON-NLS-2$
 		}
+		if (fJVMFre != null) {
+			writer.print(indent);
+			writer.print("   <" + JRE_FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$
+			writer.print(fJVMFre.toPortableString());
+			writer.println("</" + JRE_FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$
+		}
 		if (fJVMMac != null) {
 			writer.print(indent);
 			writer.print("   <" + JRE_MAC + ">"); //$NON-NLS-1$ //$NON-NLS-2$
