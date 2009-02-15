--- plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/PluginConverterImpl.java.orig	2008-08-02 13:21:52.000000000 -0400
+++ plugins/org.eclipse.osgi/eclipseAdaptor/src/org/eclipse/core/runtime/internal/adaptor/PluginConverterImpl.java	2008-08-02 13:22:39.000000000 -0400
@@ -68,7 +68,7 @@
 	static public final String FRAGMENT_MANIFEST = "fragment.xml"; //$NON-NLS-1$
 	static public final String GENERATED_FROM = "Generated-from"; //$NON-NLS-1$
 	static public final String MANIFEST_TYPE_ATTRIBUTE = "type"; //$NON-NLS-1$
-	private static final String[] OS_LIST = {org.eclipse.osgi.service.environment.Constants.OS_AIX, org.eclipse.osgi.service.environment.Constants.OS_HPUX, org.eclipse.osgi.service.environment.Constants.OS_LINUX, org.eclipse.osgi.service.environment.Constants.OS_MACOSX, org.eclipse.osgi.service.environment.Constants.OS_QNX, org.eclipse.osgi.service.environment.Constants.OS_SOLARIS, org.eclipse.osgi.service.environment.Constants.OS_WIN32};
+	private static final String[] OS_LIST = {org.eclipse.osgi.service.environment.Constants.OS_AIX, org.eclipse.osgi.service.environment.Constants.OS_HPUX, org.eclipse.osgi.service.environment.Constants.OS_LINUX, org.eclipse.osgi.service.environment.Constants.OS_FREEBSD, org.eclipse.osgi.service.environment.Constants.OS_MACOSX, org.eclipse.osgi.service.environment.Constants.OS_QNX, org.eclipse.osgi.service.environment.Constants.OS_SOLARIS, org.eclipse.osgi.service.environment.Constants.OS_WIN32};
 	protected static final String PI_RUNTIME = "org.eclipse.core.runtime"; //$NON-NLS-1$
 	protected static final String PI_BOOT = "org.eclipse.core.boot"; //$NON-NLS-1$
 	protected static final String PI_RUNTIME_COMPATIBILITY = "org.eclipse.core.runtime.compatibility"; //$NON-NLS-1$
