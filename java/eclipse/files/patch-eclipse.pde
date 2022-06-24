diff -ru eclipse.pde/build/org.eclipse.pde.build/scripts/productBuild/allElements.xml eclipse.pde/build/org.eclipse.pde.build/scripts/productBuild/allElements.xml
--- eclipse.pde/build/org.eclipse.pde.build/scripts/productBuild/allElements.xml	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/scripts/productBuild/allElements.xml	0000-00-00 00:00:00.000000000 +0000
@@ -59,10 +59,10 @@
 		</ant>
  	</target>
 	
-	<property name="assemble.org.eclipse.pde.build.container.feature.linux.gtk.x86_64" value="true" />
- 	<target name="assemble.org.eclipse.pde.build.container.feature.linux.gtk.x86_64">
+	<property name="assemble.org.eclipse.pde.build.container.feature.freebsd.gtk.amd64" value="true" />
+ 	<target name="assemble.org.eclipse.pde.build.container.feature.freebsd.gtk.amd64">
  		<ant antfile="${assembleScriptName}" dir="${buildDirectory}">			
- 			<property name="archiveName" value="${archiveNamePrefix}-linux.gtk.x86_64.zip"/>
+ 			<property name="archiveName" value="${archiveNamePrefix}-freebsd.gtk.amd64.zip"/>
 		</ant>
  	</target>
 	
diff -ru eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java
--- eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/Utils.java	0000-00-00 00:00:00.000000000 +0000
@@ -694,7 +694,7 @@
 			arguments.add("-sf"); //$NON-NLS-1$
 			arguments.add(links[i]);
 			arguments.add(links[i + 1]);
-			script.printExecTask("ln", dir, arguments, "Linux"); //$NON-NLS-1$ //$NON-NLS-2$
+			script.printExecTask("ln", dir, arguments, "Linux,FreeBSD"); //$NON-NLS-1$ //$NON-NLS-2$
 			arguments.clear();
 		}
 	}
diff -ru eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java
--- eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/src/org/eclipse/pde/internal/build/builder/ModelBuildScriptGenerator.java	0000-00-00 00:00:00.000000000 +0000
@@ -912,7 +912,7 @@
 		for (int i = 0; i < links.length; i += 2) {
 			arguments.add(links[i]);
 			arguments.add(links[i + 1]);
-			script.printExecTask("ln -s", dir, arguments, "Linux"); //$NON-NLS-1$ //$NON-NLS-2$
+			script.printExecTask("ln -s", dir, arguments, "Linux,FreeBSD"); //$NON-NLS-1$ //$NON-NLS-2$
 			arguments.clear();
 		}
 	}
diff -ru eclipse.pde/build/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java eclipse.pde/build/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java
--- eclipse.pde/build/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/src_ant/org/eclipse/pde/internal/build/tasks/JNLPGenerator.java	0000-00-00 00:00:00.000000000 +0000
@@ -308,8 +308,8 @@
 			return "Windows"; //$NON-NLS-1$
 		if ("macosx".equalsIgnoreCase(os)) //$NON-NLS-1$
 			return "Mac"; //$NON-NLS-1$
-		if ("linux".equalsIgnoreCase(os)) //$NON-NLS-1$
-			return "Linux"; //$NON-NLS-1$
+		if ("freebsd".equalsIgnoreCase(os)) //$NON-NLS-1$
+			return "FreeBSD"; //$NON-NLS-1$
 		if ("solaris".equalsIgnoreCase(os)) //$NON-NLS-1$
 			return "Solaris"; //$NON-NLS-1$
 		if ("hpux".equalsIgnoreCase(os)) //$NON-NLS-1$
diff -ru eclipse.pde/build/org.eclipse.pde.build/templates/packager/customTargets.xml eclipse.pde/build/org.eclipse.pde.build/templates/packager/customTargets.xml
--- eclipse.pde/build/org.eclipse.pde.build/templates/packager/customTargets.xml	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/templates/packager/customTargets.xml	0000-00-00 00:00:00.000000000 +0000
@@ -19,9 +19,9 @@
 		</ant>
 	</target>
 	
-	<target name="assemble.linux.gtk.x86_64.xml">
+	<target name="assemble.freebsd.gtk.amd64.xml">
 		<ant antfile="${assembleScriptName}" >
-			<property name="archiveName" value="${archiveNamePrefix}-linux.gtk.x86_64.zip"/>
+			<property name="archiveName" value="${archiveNamePrefix}-freebsd.gtk.amd64.zip"/>
 		</ant>
 	</target>
 		
diff -ru eclipse.pde/build/org.eclipse.pde.build/templates/packager/packaging.properties eclipse.pde/build/org.eclipse.pde.build/templates/packager/packaging.properties
--- eclipse.pde/build/org.eclipse.pde.build/templates/packager/packaging.properties	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/build/org.eclipse.pde.build/templates/packager/packaging.properties	0000-00-00 00:00:00.000000000 +0000
@@ -19,4 +19,4 @@
 root.permissions.755=eclipse,*.so*
 
 root.win32.win32.x86_64=eclipse.exe, eclipsec.exe
-root.linux.gtk.x86_64=eclipse,libcairo-swt.so,about_files/,about.html,icon.xpm
+root.freebsd.gtk.amd64=eclipse,libcairo-swt.so,about_files/,about.html,icon.xpm
diff -ru eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java
--- eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/ConfigurationSection.java	0000-00-00 00:00:00.000000000 +0000
@@ -56,8 +56,8 @@
 	private FormEntry fCustomEntry;
 	private boolean fBlockChanges;
 
-	private static final String[] TAB_LABELS = { "linux", "macosx", "win32" }; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
-	private static final String[] TAB_OS = { Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_WIN32 };
+	private static final String[] TAB_LABELS = { "freebsd", "linux", "macosx", "win32" }; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
+	private static final String[] TAB_OS = { Platform.OS_FREEBSD, Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_WIN32 };
 
 	private CTabFolder fTabFolder;
 	private int fLastTab;
diff -ru eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java
--- eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/editor/product/JRESection.java	0000-00-00 00:00:00.000000000 +0000
@@ -69,8 +69,8 @@
 	private ComboViewerPart fEEsCombo;
 	private boolean fBlockChanges;
 
-	private static final String[] TAB_LABELS = { "linux", "macosx", "win32" }; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
-	private static final String[] TAB_OS = { Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_WIN32 };
+	private static final String[] TAB_LABELS = { "freebsd", "linux", "macosx", "win32" }; //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
+	private static final String[] TAB_OS = { Platform.OS_FREEBSD, Platform.OS_LINUX, Platform.OS_MACOSX, Platform.OS_WIN32 };
 
 	private CTabFolder fTabFolder;
 	private int fLastTab;
diff -ru eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java
--- eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/ui/org.eclipse.pde.ui/src/org/eclipse/pde/internal/ui/wizards/product/ProductIntroOperation.java	0000-00-00 00:00:00.000000000 +0000
@@ -130,7 +130,7 @@
 		implementation.setName("implementation"); //$NON-NLS-1$
 		implementation.setAttribute("kind", "html"); //$NON-NLS-1$ //$NON-NLS-2$
 		implementation.setAttribute("style", "content/shared.css"); //$NON-NLS-1$ //$NON-NLS-2$
-		implementation.setAttribute("os", "win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
+		implementation.setAttribute("os", "freebsd,win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
 
 		presentation.add(implementation);
 
diff -ru eclipse.pde/ui/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java eclipse.pde/ui/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java
--- eclipse.pde/ui/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/ui/org.eclipse.pde.ui.templates/src/org/eclipse/pde/internal/ui/templates/rcp/IntroTemplate.java	0000-00-00 00:00:00.000000000 +0000
@@ -162,7 +162,7 @@
 		presentationElement.setAttribute("home-page-id", "root"); //$NON-NLS-1$ //$NON-NLS-2$
 		IPluginElement implementationElement = factory.createElement(presentationElement);
 		implementationElement.setName("implementation"); //$NON-NLS-1$
-		implementationElement.setAttribute("os", "win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
+		implementationElement.setAttribute("os", "freebsd,win32,linux,macosx"); //$NON-NLS-1$ //$NON-NLS-2$
 		if (getTargetVersion() == 3.0)
 			implementationElement.setAttribute("style", "content/shared.css"); //$NON-NLS-1$//$NON-NLS-2$
 
diff -ru eclipse.pde/ui/org.eclipse.pde.ui.templates/templates_3.5/E4Application/$pluginId$.product eclipse.pde/ui/org.eclipse.pde.ui.templates/templates_3.5/E4Application/$pluginId$.product
--- eclipse.pde/ui/org.eclipse.pde.ui.templates/templates_3.5/E4Application/$pluginId$.product	0000-00-00 00:00:00.000000000 +0000
+++ eclipse.pde/ui/org.eclipse.pde.ui.templates/templates_3.5/E4Application/$pluginId$.product	0000-00-00 00:00:00.000000000 +0000
@@ -84,8 +84,9 @@
       <plugin id="org.osgi.util.promise"/>
       <plugin id="org.eclipse.swt"/>
       <plugin id="org.eclipse.swt.cocoa.macosx.x86_64" fragment="true"/>
-      <plugin id="org.eclipse.swt.gtk.linux.ppc64" fragment="true"/>
-      <plugin id="org.eclipse.swt.gtk.linux.x86_64" fragment="true"/>
+      <plugin id="org.eclipse.swt.gtk.freebsd.powerpc64" fragment="true"/>
+      <plugin id="org.eclipse.swt.gtk.freebsd.powerpc64le" fragment="true"/>
+      <plugin id="org.eclipse.swt.gtk.freebsd.amd64" fragment="true"/>
       <plugin id="org.eclipse.swt.win32.win32.x86_64" fragment="true"/>
       <plugin id="org.eclipse.urischeme"/>
       <plugin id="org.w3c.css.sac"/>
