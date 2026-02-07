--- src/java/de/tu_darmstadt/informatik/rbg/bstickler/udflib/UDFImageBuilderFile.java.orig	2016-06-20 14:54:06 UTC
+++ src/java/de/tu_darmstadt/informatik/rbg/bstickler/udflib/UDFImageBuilderFile.java
@@ -32,6 +32,14 @@ public class UDFImageBuilderFile impleme
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
