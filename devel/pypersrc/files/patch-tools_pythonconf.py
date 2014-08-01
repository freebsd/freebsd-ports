--- ./tools/pythonconf.py.orig	2012-01-05 18:59:30.000000000 +0100
+++ ./tools/pythonconf.py	2014-08-01 16:40:40.000000000 +0200
@@ -47,7 +47,7 @@
         else:
             # GNU
             # ldlibflags: last char must stay a space
-            ldlibflags = "-L" + sys.prefix + "/lib/python" + str(pythonVersion) + "/config" + " -lpython" + str(pythonVersion) + " "
+            ldlibflags = "-L" + sys.prefix + "/lib" + " -lpython" + str(pythonVersion) + " "
             if find( sys.platform, "bsd" ) != -1:
                 ldlibflags += "-pthread "
             else:
