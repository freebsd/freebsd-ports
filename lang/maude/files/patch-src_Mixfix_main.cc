--- src/Mixfix/main.cc.orig	Wed Apr  5 22:46:48 2006
+++ src/Mixfix/main.cc	Wed Apr  5 22:49:23 2006
@@ -284,6 +284,11 @@
       directory = ".";
       return true;
     }
+  if (directoryManager.checkAccess("%%DATADIR%%", fileName, R_OK))
+    {
+      directory = "%%DATADIR%%";
+      return true;
+    }
   IssueWarning(LineNumber(FileTable::AUTOMATIC) <<
 	       ": unable to locate file: " << QUOTE(fileName));
   return false;
@@ -307,6 +312,11 @@
 	  directoryManager.checkAccess(executableDirectory, fileName, R_OK, ext))
 	{
 	  directory = executableDirectory;
+	  return true;
+	}
+      if (directoryManager.checkAccess("%%DATADIR%%", fileName, R_OK))
+	{
+	  directory = "%%DATADIR%%";
 	  return true;
 	}
     }
