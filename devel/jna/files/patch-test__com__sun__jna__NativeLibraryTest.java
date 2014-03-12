--- test/com/sun/jna/NativeLibraryTest.java.orig	2013-07-04 14:42:30.000000000 -0400
+++ test/com/sun/jna/NativeLibraryTest.java	2014-03-12 14:42:59.000000000 -0400
@@ -190,7 +190,7 @@
     	lib1_1.deleteOnExit();
     	List path = Arrays.asList(new String[] { dir.getAbsolutePath() });
     	assertEquals("Latest versioned library not found when unversioned requested",
-                     lib1_1.getAbsolutePath(),	
+                     lib1_1.getCanonicalPath(),	
                      NativeLibrary.matchLibrary(name, path));
     }
     
@@ -205,7 +205,7 @@
         lib1.deleteOnExit();
     	List path = Arrays.asList(new String[] { dir.getAbsolutePath() });
     	assertEquals("Library with similar prefix should be ignored",
-                     lib0.getAbsolutePath(),	
+                     lib0.getCanonicalPath(),	
                      NativeLibrary.matchLibrary(name, path));
     }
 
