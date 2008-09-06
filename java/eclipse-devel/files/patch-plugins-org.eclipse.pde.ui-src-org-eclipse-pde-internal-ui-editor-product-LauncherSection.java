--- plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/LauncherSection.java.orig	2008-08-02 17:40:49.000000000 -0400
+++ plugins/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/LauncherSection.java	2008-08-02 17:46:15.000000000 -0400
@@ -61,6 +61,7 @@
 	private Composite fNotebook;
 	private StackLayout fNotebookLayout;
 	private Composite fLinuxSection;
+	private Composite fFreeBSDSection;
 	private Composite fMacSection;
 	private Composite fSolarisSection;
 	private Composite fWin32Section;
@@ -156,6 +157,7 @@
 		fNotebook.setLayout(fNotebookLayout);
 
 		fLinuxSection = addLinuxSection(fNotebook, toolkit);
+		fFreeBSDSection = addFreeBSDSection(fNotebook, toolkit);
 		fMacSection = addMacSection(fNotebook, toolkit);
 		fSolarisSection = addSolarisSection(fNotebook, toolkit);
 		fWin32Section = addWin32Section(fNotebook, toolkit);
@@ -181,20 +183,24 @@
 
 	private void createTabs() {
 		addTab("linux"); //$NON-NLS-1$
+		addTab("freebsd"); //$NON-NLS-1$
 		addTab("macosx"); //$NON-NLS-1$
 		addTab("solaris"); //$NON-NLS-1$
 		addTab("win32"); //$NON-NLS-1$
 
 		String currentTarget = TargetPlatform.getOS();
 		if ("win32".equals(currentTarget)) { //$NON-NLS-1$
-			fTabFolder.setSelection(3);
+			fTabFolder.setSelection(4);
 			fNotebookLayout.topControl = fWin32Section;
 		} else if ("macosx".equals(currentTarget)) { //$NON-NLS-1$
-			fTabFolder.setSelection(1);
+			fTabFolder.setSelection(2);
 			fNotebookLayout.topControl = fMacSection;
 		} else if ("solaris".equals(currentTarget)) { //$NON-NLS-1$
-			fTabFolder.setSelection(2);
+			fTabFolder.setSelection(3);
 			fNotebookLayout.topControl = fSolarisSection;
+		} else if ("freebsd".equals(currentTarget)) { //$NON-NLS-1$
+			fTabFolder.setSelection(1);
+			fNotebookLayout.topControl = fFreeBSDSection;
 		} else {
 			fTabFolder.setSelection(0);
 			fNotebookLayout.topControl = fLinuxSection;
@@ -306,6 +312,14 @@
 		return comp;
 	}
 
+	private Composite addFreeBSDSection(Composite parent, FormToolkit toolkit) {
+		Composite comp = createComposite(parent, toolkit);
+		createLabel(comp, toolkit, PDEUIMessages.LauncherSection_freebsdLabel, 3);
+		fIcons.add(new IconEntry(comp, toolkit, PDEUIMessages.LauncherSection_icon, ILauncherInfo.FREEBSD_ICON));
+		toolkit.paintBordersFor(comp);
+		return comp;
+	}
+
 	private Composite addSolarisSection(Composite parent, FormToolkit toolkit) {
 		Composite comp = createComposite(parent, toolkit);
 		createLabel(comp, toolkit, PDEUIMessages.LauncherSection_solarisLabel, 3);
@@ -484,12 +498,15 @@
 				fNotebookLayout.topControl = fLinuxSection;
 				break;
 			case 1 :
-				fNotebookLayout.topControl = fMacSection;
+				fNotebookLayout.topControl = fFreeBSDSection;
 				break;
 			case 2 :
-				fNotebookLayout.topControl = fSolarisSection;
+				fNotebookLayout.topControl = fMacSection;
 				break;
 			case 3 :
+				fNotebookLayout.topControl = fSolarisSection;
+				break;
+			case 4 :
 				fNotebookLayout.topControl = fWin32Section;
 				break;
 		}
