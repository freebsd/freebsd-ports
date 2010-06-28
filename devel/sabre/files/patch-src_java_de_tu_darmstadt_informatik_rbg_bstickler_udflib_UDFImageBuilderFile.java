--- src/java/de/tu_darmstadt/informatik/rbg/bstickler/udflib/UDFImageBuilderFile.java.orig	2010-06-28 11:44:55.000000000 +0200
+++ src/java/de/tu_darmstadt/informatik/rbg/bstickler/udflib/UDFImageBuilderFile.java	2010-06-28 11:46:18.000000000 +0200
@@ -32,6 +32,14 @@
 		// Symlink			// TODO: maybe support symlinks
 	}
 	
+	public UDFImageBuilderFile( String fileIdentifier, File sourceFile )
+	throws Exception
+	{
+		this(sourceFile);
+		
+		identifier = fileIdentifier;
+	}
+	
 	public UDFImageBuilderFile( File sourceFile )
 	throws Exception
 	{
