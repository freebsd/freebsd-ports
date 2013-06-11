--- tests/netx/unit/net/sourceforge/jnlp/runtime/JNLPClassLoaderTest.java.bak	2013-05-03 15:08:24.647515000 -0400
+++ tests/netx/unit/net/sourceforge/jnlp/runtime/JNLPClassLoaderTest.java	2013-06-11 17:32:48.000000000 -0400
@@ -114,7 +114,7 @@
     static private File createTempJar(String jarName, String manifestContents) throws Exception {
         File dir = new File(cleanExec(null /* current working dir */, "mktemp", "-d"));
         cleanExec(dir, "/bin/bash", "-c", "echo '" + manifestContents + "' > Manifest.txt");
-        cleanExec(dir, "jar", "-cfm", jarName, "Manifest.txt");
+        cleanExec(dir, "%%JAR%%", "-cfm", jarName, "Manifest.txt");
         return new File(dir.getAbsolutePath() + "/" + jarName);
     }
 
@@ -260,4 +260,4 @@
          });
         assertFalse(classLoader.hasMainJar());
     }
-}
\ No newline at end of file
+}
