--- de/tu_darmstadt/informatik/rbg/hatlak/eltorito/impl/ElToritoHandler.java	2009-03-22 13:35:13.000000000 +0100
+++ de/tu_darmstadt/informatik/rbg/hatlak/eltorito/impl/ElToritoHandler.java	2010-06-29 10:10:02.000000000 +0200
@@ -114,7 +114,7 @@
 		}
 
 		// Write Boot Image
-		FileDataReference fdr = new FileDataReference(config.getBootImage());
+		FileDataReference fdr = new FileDataReference(config.getBootImage().getFile());
 		data(fdr);
 
 		super.endElement();
@@ -124,7 +124,7 @@
 		// Patch the Boot Image: write 56 byte boot information table
 		// (cf. man mkisofs, section EL TORITO BOOT INFORMATION TABLE)
 		try {
-			String orgName = config.getBootImage().getAbsolutePath();
+			String orgName = config.getBootImage().getFile().getAbsolutePath();
 			File orgFile = new File(orgName);
 
 			// Compute the checksum over all 32-bit words starting at byte offset 64
@@ -173,7 +173,7 @@
 			buffer[i++] = (byte) ((lba>>16)&0xFF);
 			buffer[i++] = (byte) ((lba>>24)&0xFF);
 			// Boot file length in bytes, 7.3.1 format
-			int len = (int) config.getBootImage().getAbsoluteFile().length();
+			int len = (int) config.getBootImage().getFile().getAbsoluteFile().length();
 			buffer[i++] = (byte) (len&0xFF);
 			buffer[i++] = (byte) ((len>>8)&0xFF);
 			buffer[i++] = (byte) ((len>>16)&0xFF);
