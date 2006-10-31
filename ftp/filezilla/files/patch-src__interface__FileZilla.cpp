--- ./src/interface/FileZilla.cpp.orig	Sun Oct 15 12:36:01 2006
+++ ./src/interface/FileZilla.cpp	Tue Oct 24 20:50:08 2006
@@ -533,7 +533,6 @@
 		wxPathList pathList;
 		pathList.AddEnvList(_T("PATH"));
 		executable = pathList.FindAbsoluteValidPath(program);
-		bool found = false;
 		if (executable != _T(""))
 			found = true;
 	}
