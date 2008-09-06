--- plugins/org.eclipse.core.filesystem/src/org/eclipse/core/internal/filesystem/local/LocalFileSystem.java.orig	2008-08-02 12:35:45.000000000 -0400
+++ plugins/org.eclipse.core.filesystem/src/org/eclipse/core/internal/filesystem/local/LocalFileSystem.java	2008-08-02 12:34:53.000000000 -0400
@@ -98,7 +98,7 @@
 		String arch = System.getProperty("osgi.arch", ""); //$NON-NLS-1$ //$NON-NLS-2$
 		if (os.equals(Constants.OS_WIN32))
 			attributes |= EFS.ATTRIBUTE_ARCHIVE | EFS.ATTRIBUTE_HIDDEN;
-		else if (os.equals(Constants.OS_LINUX) || (os.equals(Constants.OS_SOLARIS) && arch.equals(Constants.ARCH_SPARC)))
+		else if (os.equals(Constants.OS_LINUX) || (os.equals(Constants.OS_FREEBSD)) || (os.equals(Constants.OS_SOLARIS) && arch.equals(Constants.ARCH_SPARC)))
 			attributes |= EFS.ATTRIBUTE_EXECUTABLE | EFS.ATTRIBUTE_SYMLINK | EFS.ATTRIBUTE_LINK_TARGET;
 		else if (os.equals(Constants.OS_MACOSX) || os.equals(Constants.OS_HPUX) || os.equals(Constants.OS_QNX))
 			attributes |= EFS.ATTRIBUTE_EXECUTABLE;
