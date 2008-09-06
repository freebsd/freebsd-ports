--- plugins/org.eclipse.equinox.p2.metadata.generator/src/org/eclipse/equinox/internal/p2/metadata/generator/features/ProductFile.java.orig	2008-08-02 15:21:00.000000000 -0400
+++ plugins/org.eclipse.equinox.p2.metadata.generator/src/org/eclipse/equinox/internal/p2/metadata/generator/features/ProductFile.java	2008-08-02 15:20:23.000000000 -0400
@@ -28,11 +28,13 @@
 
 	private static final String PROGRAM_ARGS = "programArgs"; //$NON-NLS-1$
 	private static final String PROGRAM_ARGS_LINUX = "programArgsLin"; //$NON-NLS-1$
+	private static final String PROGRAM_ARGS_FREEBSD = "programArgsFre"; //$NON-NLS-1$
 	private static final String PROGRAM_ARGS_MAC = "programArgsMac"; //$NON-NLS-1$
 	private static final String PROGRAM_ARGS_SOLARIS = "programArgsSol"; //$NON-NLS-1$
 	private static final String PROGRAM_ARGS_WIN = "programArgsWin"; //$NON-NLS-1$
 	private static final String VM_ARGS = "vmArgs"; //$NON-NLS-1$
 	private static final String VM_ARGS_LINUX = "vmArgsLin"; //$NON-NLS-1$
+	private static final String VM_ARGS_FREEBSD = "vmArgsFre"; //$NON-NLS-1$
 	private static final String VM_ARGS_MAC = "vmArgsMac"; //$NON-NLS-1$
 	private static final String VM_ARGS_SOLARIS = "vmArgsSol"; //$NON-NLS-1$
 	private static final String VM_ARGS_WIN = "vmArgsWin"; //$NON-NLS-1$
@@ -51,6 +53,7 @@
 
 	private static final String OS_WIN32 = "win32";//$NON-NLS-1$
 	private static final String OS_LINUX = "linux";//$NON-NLS-1$
+	private static final String OS_FREEBSD = "freebsd";//$NON-NLS-1$
 	private static final String OS_SOLARIS = "solaris";//$NON-NLS-1$
 	private static final String OS_MACOSX = "macosx";//$NON-NLS-1$
 
@@ -72,15 +75,17 @@
 	private static final int STATE_FEATURES = 5;
 	private static final int STATE_PROGRAM_ARGS = 6;
 	private static final int STATE_PROGRAM_ARGS_LINUX = 7;
-	private static final int STATE_PROGRAM_ARGS_MAC = 8;
-	private static final int STATE_PROGRAM_ARGS_SOLARIS = 9;
-	private static final int STATE_PROGRAM_ARGS_WIN = 10;
-	private static final int STATE_VM_ARGS = 11;
-	private static final int STATE_VM_ARGS_LINUX = 12;
-	private static final int STATE_VM_ARGS_MAC = 13;
-	private static final int STATE_VM_ARGS_SOLARIS = 14;
-	private static final int STATE_VM_ARGS_WIN = 15;
-	private static final int STATE_CONFIG_INI = 16;
+	private static final int STATE_PROGRAM_ARGS_FREEBSD = 8;
+	private static final int STATE_PROGRAM_ARGS_MAC = 9;
+	private static final int STATE_PROGRAM_ARGS_SOLARIS = 10;
+	private static final int STATE_PROGRAM_ARGS_WIN = 11;
+	private static final int STATE_VM_ARGS = 12;
+	private static final int STATE_VM_ARGS_LINUX = 13;
+	private static final int STATE_VM_ARGS_FREEBSD = 14;
+	private static final int STATE_VM_ARGS_MAC = 15;
+	private static final int STATE_VM_ARGS_SOLARIS = 16;
+	private static final int STATE_VM_ARGS_WIN = 17;
+	private static final int STATE_CONFIG_INI = 18;
 
 	private int state = STATE_START;
 
@@ -233,6 +238,8 @@
 			key = VM_ARGS_WIN;
 		} else if (os.equals(OS_LINUX)) {
 			key = VM_ARGS_LINUX;
+		} else if (os.equals(OS_FREEBSD)) {
+			key = VM_ARGS_FREEBSD;
 		} else if (os.equals(OS_MACOSX)) {
 			key = VM_ARGS_MAC;
 		} else if (os.equals(OS_SOLARIS)) {
@@ -256,6 +263,8 @@
 			key = PROGRAM_ARGS_WIN;
 		} else if (os.equals(OS_LINUX)) {
 			key = PROGRAM_ARGS_LINUX;
+		} else if (os.equals(OS_FREEBSD)) {
+			key = PROGRAM_ARGS_FREEBSD;
 		} else if (os.equals(OS_MACOSX)) {
 			key = PROGRAM_ARGS_MAC;
 		} else if (os.equals(OS_SOLARIS)) {
@@ -311,6 +320,8 @@
 					processWin(attributes);
 				} else if (OS_LINUX.equals(localName)) {
 					processLinux(attributes);
+				} else if (OS_FREEBSD.equals(localName)) {
+					processFreeBSD(attributes);
 				} else if (OS_MACOSX.equals(localName)) {
 					processMac(attributes);
 				}
@@ -326,6 +337,8 @@
 					state = STATE_PROGRAM_ARGS;
 				} else if (PROGRAM_ARGS_LINUX.equals(localName)) {
 					state = STATE_PROGRAM_ARGS_LINUX;
+				} else if (PROGRAM_ARGS_FREEBSD.equals(localName)) {
+					state = STATE_PROGRAM_ARGS_FREEBSD;
 				} else if (PROGRAM_ARGS_MAC.equals(localName)) {
 					state = STATE_PROGRAM_ARGS_MAC;
 				} else if (PROGRAM_ARGS_SOLARIS.equals(localName)) {
@@ -336,6 +349,8 @@
 					state = STATE_VM_ARGS;
 				} else if (VM_ARGS_LINUX.equals(localName)) {
 					state = STATE_VM_ARGS_LINUX;
+				} else if (VM_ARGS_FREEBSD.equals(localName)) {
+					state = STATE_VM_ARGS_FREEBSD;
 				} else if (VM_ARGS_MAC.equals(localName)) {
 					state = STATE_VM_ARGS_MAC;
 				} else if (VM_ARGS_SOLARIS.equals(localName)) {
@@ -380,11 +395,13 @@
 
 			case STATE_PROGRAM_ARGS :
 			case STATE_PROGRAM_ARGS_LINUX :
+			case STATE_PROGRAM_ARGS_FREEBSD :
 			case STATE_PROGRAM_ARGS_MAC :
 			case STATE_PROGRAM_ARGS_SOLARIS :
 			case STATE_PROGRAM_ARGS_WIN :
 			case STATE_VM_ARGS :
 			case STATE_VM_ARGS_LINUX :
+			case STATE_VM_ARGS_FREEBSD :
 			case STATE_VM_ARGS_MAC :
 			case STATE_VM_ARGS_SOLARIS :
 			case STATE_VM_ARGS_WIN :
@@ -408,6 +425,9 @@
 			case STATE_PROGRAM_ARGS_LINUX :
 				addLaunchArgumentToMap(PROGRAM_ARGS_LINUX, String.valueOf(ch, start, length));
 				break;
+			case STATE_PROGRAM_ARGS_FREEBSD :
+				addLaunchArgumentToMap(PROGRAM_ARGS_FREEBSD, String.valueOf(ch, start, length));
+				break;
 			case STATE_PROGRAM_ARGS_MAC :
 				addLaunchArgumentToMap(PROGRAM_ARGS_MAC, String.valueOf(ch, start, length));
 				break;
@@ -423,6 +443,9 @@
 			case STATE_VM_ARGS_LINUX :
 				addLaunchArgumentToMap(VM_ARGS_LINUX, String.valueOf(ch, start, length));
 				break;
+			case STATE_VM_ARGS_FREEBSD :
+				addLaunchArgumentToMap(VM_ARGS_FREEBSD, String.valueOf(ch, start, length));
+				break;
 			case STATE_VM_ARGS_MAC :
 				addLaunchArgumentToMap(VM_ARGS_MAC, String.valueOf(ch, start, length));
 				break;
@@ -555,6 +578,12 @@
 		result.add(attributes.getValue("icon")); //$NON-NLS-1$
 	}
 
+	private void processFreeBSD(Attributes attributes) {
+		if (!osMatch(OS_FREEBSD))
+			return;
+		result.add(attributes.getValue("icon")); //$NON-NLS-1$
+	}
+
 	private void processMac(Attributes attributes) {
 		if (!osMatch(OS_MACOSX))
 			return;
