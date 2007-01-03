--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/org/eclipse/swt/internal/mozilla/XPCOM.java.orig	Wed Nov 29 14:11:42 2006
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/common/org/eclipse/swt/internal/mozilla/XPCOM.java	Wed Nov 29 14:14:30 2006
@@ -89,6 +89,7 @@
 	public static final int NS_ERROR_HTMLPARSER_UNRESOLVEDDTD = 0x804e03f3;
 	public static final int NS_ERROR_FILE_NOT_FOUND = 0x80520012;
 	public static final String NS_APP_APPLICATION_REGISTRY_DIR = "AppRegD"; //$NON-NLS-1$
+	public static final String NS_APP_USER_PROFILE_50_DIR = "ProfD"; //$NON-NLS-1$
 
 public static final native void memmove(nsID dest, int /*long*/ src, int nbytes);
 public static final native void memmove(int /*long*/ dest, nsID src, int nbytes);
@@ -103,9 +104,8 @@
 public static final native void memmove(byte[] dest, char[] src, int nbytes);
 public static final native int NS_GetComponentManager(int /*long*/[] result);
 public static final native int NS_GetServiceManager(int /*long*/[] result);
-public static final native int NS_InitEmbedding(int /*long*/ aMozBinDirectory, int /*long*/ aAppFileLocProvider);
+public static final native int NS_InitXPCOM3(int /*long*/ result, int /*long*/ binDirectory, int /*long*/ appFileLocationProvider, int /*long*/ staticComponents, int componentCount);
 public static final native int NS_NewLocalFile(int /*long*/ path, boolean followLinks, int /*long*/[] result);
-public static final native int NS_TermEmbedding();
 public static final native int strlen_PRUnichar(int /*long*/ s);
 public static final native int /*long*/ nsEmbedCString_new();
 public static final native int /*long*/ nsEmbedCString_new(byte[] aString, int length);
