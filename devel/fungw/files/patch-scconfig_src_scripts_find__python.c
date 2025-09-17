--- scconfig/src/scripts/find_python.c.orig	2025-09-17 16:31:52 UTC
+++ scconfig/src/scripts/find_python.c
@@ -47,7 +47,7 @@ static int find_script_python_(const char *name, int l
 		NL;
 	char *lib_py =
 		NL "import distutils.sysconfig;"
-		NL "print ('-L' + distutils.sysconfig.PREFIX.replace('\\\\','/') + '/libs')"
+		NL "print ('-L' + distutils.sysconfig.PREFIX.replace('\\\\','/') + '/lib')"
 		NL "import sys;"
-		NL "print ('-lpython' + str(sys.version_info[0]) + str(sys.version_info[1]))"
+		NL "print ('-lpython' + str(sys.version_info[0]) + '.' + str(sys.version_info[1]))"
 		NL;
