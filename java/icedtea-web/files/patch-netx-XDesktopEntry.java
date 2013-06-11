--- netx/net/sourceforge/jnlp/util/XDesktopEntry.java.orig	2013-05-03 15:08:24.357518000 -0400
+++ netx/net/sourceforge/jnlp/util/XDesktopEntry.java	2013-06-11 11:04:56.000000000 -0400
@@ -102,7 +102,7 @@
         }
 
         //Shortcut executes the jnlp from cache and system preferred java..
-        fileContents += "Exec=" + "javaws" + " \"" + cacheFile.getAbsolutePath() + "\"\n";
+        fileContents += "Exec=" + "itweb-javaws" + " \"" + cacheFile.getAbsolutePath() + "\"\n";
 
         return new StringReader(fileContents);
 
