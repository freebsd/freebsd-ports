--- rts/build/scons/config.py.orig	2007-12-18 14:56:55.000000000 +0300
+++ rts/build/scons/config.py	2008-01-10 22:47:09.000000000 +0300
@@ -205,6 +205,9 @@
 
 def check_java(env, conf):
 	print "Checking for Java...",
+	env.AppendUnique(CPPPATH = [os.environ['JAVA_INC']])
+	env.AppendUnique(CPPPATH = [os.path.join(os.environ['JAVA_INC'], "freebsd")])
+	return
 	if env.has_key('javapath') and env['javapath']:
 		env.AppendUnique(CPPPATH = [env['javapath']])
 		env.AppendUnique(CPPPATH = [os.path.join(env['javapath'], "linux")])
