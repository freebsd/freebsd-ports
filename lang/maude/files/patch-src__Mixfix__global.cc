--- ./src/Mixfix/global.cc.orig	2006-10-07 01:09:16.000000000 +0200
+++ ./src/Mixfix/global.cc	2011-11-10 19:36:44.000000000 +0100
@@ -89,6 +89,11 @@
 	  directory = executableDirectory;
 	  return true;
 	}
+      if (directoryManager.checkAccess(MAUDE_DATADIR, fileName, R_OK, ext))
+	{
+	  directory = MAUDE_DATADIR;
+	  return true;
+	}
     }
   else if (p + 1 < userFileName.length())
     {
