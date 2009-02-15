--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/ArgumentsInfo.java.orig	2008-08-02 21:24:52.884965179 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/product/ArgumentsInfo.java	2008-08-02 21:24:20.894767822 -0400
@@ -21,12 +21,14 @@
 	private static final long serialVersionUID = 1L;
 	private String fProgramArgs = ""; //$NON-NLS-1$
 	private String fProgramArgsLin = ""; //$NON-NLS-1$
+	private String fProgramArgsFre = ""; //$NON-NLS-1$
 	private String fProgramArgsMac = ""; //$NON-NLS-1$
 	private String fProgramArgsSol = ""; //$NON-NLS-1$
 	private String fProgramArgsWin = ""; //$NON-NLS-1$
 
 	private String fVMArgs = ""; //$NON-NLS-1$
 	private String fVMArgsLin = ""; //$NON-NLS-1$
+	private String fVMArgsFre = ""; //$NON-NLS-1$
 	private String fVMArgsMac = ""; //$NON-NLS-1$
 	private String fVMArgsSol = ""; //$NON-NLS-1$
 	private String fVMArgsWin = ""; //$NON-NLS-1$
@@ -52,6 +54,12 @@
 				if (isEditable())
 					firePropertyChanged(P_PROG_ARGS_LIN, old, fProgramArgsLin);
 				break;
+			case L_ARGS_FREEBSD :
+				old = fProgramArgsFre;
+				fProgramArgsFre = args;
+				if (isEditable())
+					firePropertyChanged(P_PROG_ARGS_FRE, old, fProgramArgsFre);
+				break;
 			case L_ARGS_MACOS :
 				old = fProgramArgsMac;
 				fProgramArgsMac = args;
@@ -79,6 +87,8 @@
 				return fProgramArgs;
 			case L_ARGS_LINUX :
 				return fProgramArgsLin;
+			case L_ARGS_FREEBSD :
+				return fProgramArgsFre;
 			case L_ARGS_MACOS :
 				return fProgramArgsMac;
 			case L_ARGS_SOLAR :
@@ -94,6 +104,8 @@
 			return getCompleteArgs(getProgramArguments(L_ARGS_WIN32), fProgramArgs);
 		} else if (Platform.OS_LINUX.equals(os)) {
 			return getCompleteArgs(getProgramArguments(L_ARGS_LINUX), fProgramArgs);
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			return getCompleteArgs(getProgramArguments(L_ARGS_FREEBSD), fProgramArgs);
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			return getCompleteArgs(getProgramArguments(L_ARGS_MACOS), fProgramArgs);
 		} else if (Platform.OS_SOLARIS.equals(os)) {
@@ -120,6 +132,12 @@
 				if (isEditable())
 					firePropertyChanged(P_VM_ARGS_LIN, old, fVMArgsLin);
 				break;
+			case L_ARGS_FREEBSD :
+				old = fVMArgsFre;
+				fVMArgsFre = args;
+				if (isEditable())
+					firePropertyChanged(P_VM_ARGS_FRE, old, fVMArgsFre);
+				break;
 			case L_ARGS_MACOS :
 				old = fVMArgsMac;
 				fVMArgsMac = args;
@@ -147,6 +165,8 @@
 				return fVMArgs;
 			case L_ARGS_LINUX :
 				return fVMArgsLin;
+			case L_ARGS_FREEBSD :
+				return fVMArgsFre;
 			case L_ARGS_MACOS :
 				return fVMArgsMac;
 			case L_ARGS_SOLAR :
@@ -162,6 +182,8 @@
 			return getCompleteArgs(getVMArguments(L_ARGS_WIN32), fVMArgs);
 		} else if (Platform.OS_LINUX.equals(os)) {
 			return getCompleteArgs(getVMArguments(L_ARGS_LINUX), fVMArgs);
+		} else if (Platform.OS_FREEBSD.equals(os)) {
+			return getCompleteArgs(getVMArguments(L_ARGS_FREEBSD), fVMArgs);
 		} else if (Platform.OS_MACOSX.equals(os)) {
 			return getCompleteArgs(getVMArguments(L_ARGS_MACOS), fVMArgs);
 		} else if (Platform.OS_SOLARIS.equals(os)) {
@@ -187,6 +209,8 @@
 					fProgramArgs = getText(child);
 				} else if (child.getNodeName().equals(P_PROG_ARGS_LIN)) {
 					fProgramArgsLin = getText(child);
+				} else if (child.getNodeName().equals(P_PROG_ARGS_FRE)) {
+					fProgramArgsFre = getText(child);
 				} else if (child.getNodeName().equals(P_PROG_ARGS_MAC)) {
 					fProgramArgsMac = getText(child);
 				} else if (child.getNodeName().equals(P_PROG_ARGS_SOL)) {
@@ -197,6 +221,8 @@
 					fVMArgs = getText(child);
 				} else if (child.getNodeName().equals(P_VM_ARGS_LIN)) {
 					fVMArgsLin = getText(child);
+				} else if (child.getNodeName().equals(P_VM_ARGS_FRE)) {
+					fVMArgsFre = getText(child);
 				} else if (child.getNodeName().equals(P_VM_ARGS_MAC)) {
 					fVMArgsMac = getText(child);
 				} else if (child.getNodeName().equals(P_VM_ARGS_SOL)) {
@@ -225,6 +251,9 @@
 		if (fProgramArgsLin.length() > 0) {
 			writer.println(indent + "   " + "<" + P_PROG_ARGS_LIN + ">" + getWritableString(fProgramArgsLin) + "</" + P_PROG_ARGS_LIN + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
 		}
+		if (fProgramArgsFre.length() > 0) {
+			writer.println(indent + "   " + "<" + P_PROG_ARGS_FRE + ">" + getWritableString(fProgramArgsFre) + "</" + P_PROG_ARGS_FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
+		}
 		if (fProgramArgsMac.length() > 0) {
 			writer.println(indent + "   " + "<" + P_PROG_ARGS_MAC + ">" + getWritableString(fProgramArgsMac) + "</" + P_PROG_ARGS_MAC + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
 		}
@@ -240,6 +269,9 @@
 		if (fVMArgsLin.length() > 0) {
 			writer.println(indent + "   " + "<" + P_VM_ARGS_LIN + ">" + getWritableString(fVMArgsLin) + "</" + P_VM_ARGS_LIN + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
 		}
+                if (fVMArgsFre.length() > 0) {
+                        writer.println(indent + "   " + "<" + P_VM_ARGS_FRE + ">" + getWritableString(fVMArgsFre) + "</" + P_VM_ARGS_FRE + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
+                }
 		if (fVMArgsMac.length() > 0) {
 			writer.println(indent + "   " + "<" + P_VM_ARGS_MAC + ">" + getWritableString(fVMArgsMac) + "</" + P_VM_ARGS_MAC + ">"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$ //$NON-NLS-4$ //$NON-NLS-5$
 		}
