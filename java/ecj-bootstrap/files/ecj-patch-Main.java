Dirty hack...recognize sun.boot.class.path for implicit bootclasspath.

--- org/eclipse/jdt/internal/compiler/batch/Main.java Fri Aug  4 15:14:29 2006
+++ org/eclipse/jdt/internal/compiler/batch/Main.java Fri Aug  4 16:04:13 2006
@@ -2448,6 +2448,16 @@
 				}
 			}
  		}
+
+	 	/*
+	 	 * Handle sun.boot.class.path
+	 	 */
+		String sunboot = System.getProperty("sun.boot.class.path");
+		File sunbootclasspath = new File (sunboot);
+		FileSystem.Classpath classpath = FileSystem.getClasspath(
+							sunbootclasspath.getAbsolutePath(),
+									null, false, null); 
+		if (classpath != null) {bootclasspaths.add(classpath);}
 	}
 	final int classpathsSize = classpaths.size();
 	if (classpaths.size() != 0) {
