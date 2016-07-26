--- configure.py.orig	2002-05-01 03:59:28 UTC
+++ configure.py
@@ -7,7 +7,7 @@ import string
 import getopt
 
 usagemessage = 'usage: ' + sys.argv[0] + ' [-d NAME] [-i] [-I /dir/path] [-L /dir/path] [-l]'
-usagemessage = usagemessage + '\n   or: ' + sys.argv[0] + ' [--driver NAME] [--integer] [--include /dir/path] [--lib /dir/path] [--list]'
+usagemessage = usagemessage + '\n   or: ' + sys.argv[0] + ' [--driver NAME] [--integer] [--include /dir/path] [--lib /dir/path] [--list] [--PIC]'
 
 helpmessage = 'Boodler configuration script\n\n' + usagemessage + '''
 
@@ -68,8 +68,8 @@ loop, but does not eliminate them entire
 '''
 
 try:
-	(opts, args) = getopt.getopt(sys.argv[1:], 'd:I:L:lih', 
-		['driver=', 'include=', 'lib=', 'list', 'integer', 'help'])
+	(opts, args) = getopt.getopt(sys.argv[1:], 'd:I:L:lihP', 
+		['driver=', 'include=', 'lib=', 'list', 'integer', 'help', 'PIC'])
 except getopt.error, ex:
 	print (sys.argv[0] + ':'), str(ex)
 	print usagemessage
@@ -101,6 +101,8 @@ for (opname, opval) in opts:
 		extraheaders.append(opval)
 	if (opname == '--lib' or opname == '-L'):
 		extralibs.append(opval)
+	if (opname == '--PIC' or opname == '-P'):
+		cflagopts = cflagopts + ' -fPIC'
 
 headerpath = extraheaders + headerpath
 libpath = extralibs + libpath
