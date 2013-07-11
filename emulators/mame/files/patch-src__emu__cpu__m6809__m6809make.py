--- src/emu/cpu/m6809/m6809make.py.orig
+++ src/emu/cpu/m6809/m6809make.py
@@ -16,7 +16,7 @@
 	if path != "":
 		path = path + '/'
 	try:
-		f = open(fname, "r")
+		f = open(fname, "rU")
 	except Exception, err:
 		print "Cannot read opcodes file %s [%s]" % (fname, err)
 		sys.exit(1)
