--- scconfig/src/scripts/find_python.c.orig	2019-01-09 06:46:09 UTC
+++ scconfig/src/scripts/find_python.c
@@ -43,13 +43,13 @@ static int find_script_python_(const char *name, int l
 
 	char *inc_py =
 		NL "import distutils.sysconfig;"
-		NL "print '-I' + distutils.sysconfig.get_python_inc().replace('\\\\','/')"
+		NL "print ('-I' + distutils.sysconfig.get_python_inc().replace('\\\\','/'))"
 		NL;
 	char *lib_py =
 		NL "import distutils.sysconfig;"
-		NL "print '-L' + distutils.sysconfig.PREFIX.replace('\\\\','/') + '/libs',;"
+		NL "print ('-L' + distutils.sysconfig.PREFIX.replace('\\\\','/') + '/lib')"
 		NL "import sys;"
-		NL "print '-lpython' + str(sys.version_info[0]) + str(sys.version_info[1])"
+		NL "print ('-lpython' + str(sys.version_info[0]) + '.' + str(sys.version_info[1]))"
 		NL;
 
 
