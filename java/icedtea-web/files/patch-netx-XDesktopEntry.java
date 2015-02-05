--- netx/net/sourceforge/jnlp/util/XDesktopEntry.java.orig	2014-08-14 06:15:47.054833000 -0400
+++ netx/net/sourceforge/jnlp/util/XDesktopEntry.java	2014-10-17 17:37:24.000000000 -0400
@@ -103,7 +103,7 @@
         }
 
         //Shortcut executes the jnlp as it was with system preferred java. It should work fine offline
-        fileContents += "Exec=" + "javaws" + " \"" + file.getSourceLocation() + "\"\n";
+        fileContents += "Exec=" + "itweb-javaws" + " \"" + file.getSourceLocation() + "\"\n";
 
         return new StringReader(fileContents);
 
