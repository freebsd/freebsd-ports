--- de/tu_darmstadt/informatik/rbg/hatlak/iso9660/ISO9660File.java	2007-03-30 17:06:58.000000000 +0200
+++ de/tu_darmstadt/informatik/rbg/hatlak/iso9660/ISO9660File.java	2010-06-29 10:10:52.000000000 +0200
@@ -29,8 +29,9 @@
 /**
  * Note: this class has a natural ordering that is inconsistent with equals.
  */
-public class ISO9660File extends File implements ISO9660HierarchyObject {
+public class ISO9660File implements ISO9660HierarchyObject {
 	public static final Pattern FILEPATTERN = Pattern.compile("^([^.]+)\\.(.+)$");
+	private File file;
 	private boolean enforceDotDelimiter = false;
 	private static final long serialVersionUID = 1L;
 	private String filename, extension;
@@ -47,7 +48,7 @@
 	 * @throws HandlerException Invalid File version or file is a directory
 	 */
 	public ISO9660File(File file, int version) throws HandlerException {
-		super(file.getPath());
+		this.file = file;
 		setName(file.getName());
 		setVersion(version);
 		id = new Object();
@@ -67,8 +68,8 @@
 	 * @throws HandlerException Invalid File version or file is a directory
 	 */
 	public ISO9660File(String pathname, int version) throws HandlerException {
-		super(pathname);
-		setName(super.getName());
+		file = new File(pathname);
+		setName(file.getName());
 		setVersion(version);
 		id = new Object();
 		enforce8plus3 = false;
@@ -99,6 +100,10 @@
 		this(pathname, 1);
 	}
 
+	public File getFile() {
+	    return file;
+	}
+	
 	/**
 	 * Returns the name of the file (without dot)
 	 * 
@@ -133,7 +138,11 @@
 		} // else
 
 		return filename;
-	}	
+	}
+	
+	public boolean isDirectory() {
+	    return file.isDirectory();
+	}
 	
 	/**
 	 * Declare this file to be a moved directory "totem pole" 
