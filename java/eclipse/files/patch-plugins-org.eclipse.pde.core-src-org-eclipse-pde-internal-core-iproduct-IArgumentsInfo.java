--- plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/iproduct/IArgumentsInfo.java.orig	2008-08-02 17:01:23.000000000 -0400
+++ plugins/org.eclipse.pde.core/src/org/eclipse/pde/internal/core/iproduct/IArgumentsInfo.java	2008-08-02 17:04:18.000000000 -0400
@@ -14,12 +14,14 @@
 
 	public static final String P_PROG_ARGS = "programArgs"; //$NON-NLS-1$
 	public static final String P_PROG_ARGS_LIN = "programArgsLin"; //$NON-NLS-1$
+	public static final String P_PROG_ARGS_FRE = "programArgsFre"; //$NON-NLS-1$
 	public static final String P_PROG_ARGS_MAC = "programArgsMac"; //$NON-NLS-1$
 	public static final String P_PROG_ARGS_SOL = "programArgsSol"; //$NON-NLS-1$
 	public static final String P_PROG_ARGS_WIN = "programArgsWin"; //$NON-NLS-1$
 
 	public static final String P_VM_ARGS = "vmArgs"; //$NON-NLS-1$
 	public static final String P_VM_ARGS_LIN = "vmArgsLin"; //$NON-NLS-1$
+	public static final String P_VM_ARGS_FRE = "vmArgsFre"; //$NON-NLS-1$
 	public static final String P_VM_ARGS_MAC = "vmArgsMac"; //$NON-NLS-1$
 	public static final String P_VM_ARGS_SOL = "vmArgsSol"; //$NON-NLS-1$
 	public static final String P_VM_ARGS_WIN = "vmArgsWin"; //$NON-NLS-1$
@@ -29,6 +31,7 @@
 	public static final int L_ARGS_MACOS = 2;
 	public static final int L_ARGS_SOLAR = 3;
 	public static final int L_ARGS_WIN32 = 4;
+	public static final int L_ARGS_FREEBSD = 5;
 
 	void setProgramArguments(String args, int platform);
 
