--- GTG/gtg.py.orig	2009-07-04 16:26:24.000000000 +0400
+++ GTG/gtg.py	2009-09-16 19:43:28.000000000 +0400
@@ -58,28 +58,24 @@
 #we allow one instance of gtg by data directory.
 def check_instance(directory):
     """ Check if gtg is already running. """
-    pidfile = directory  + "gtg.pid"
+    pidfile = os.path.join(directory, "gtg.pid")
     if not os.path.exists(pidfile):
-        f = open(pidfile, "w")
-        f.close()
-    os.chmod(pidfile, 0600)
+        open(pidfile, "w").close()
+        os.chmod(pidfile, 0600)
 
     #see if gtg is already running
-    f = open(pidfile, "r")
-    pid = f.readline()
-    f.close()
+    pid = open(pidfile, "r").readline()
     if pid:
-        p = os.system("ps --no-heading --pid " + pid)
-        p_name = os.popen("ps -f --pid " + pid).read()
+        p = os.system("/bin/ps %s >/dev/null" % pid)
+        p_name = os.popen("/bin/ps -f %s" % pid).read()
         if p == 0 and "gtg" in p_name:
             print _("gtg is already running!")
             #todo : expose the browser (will be possible when we have dbus)
             sys.exit(0)
-            
+
     #write the pid file
-    f = open(pidfile, "w")
-    f.write(str(os.getpid()))
-    f.close()
+    with open(pidfile, "w") as f:
+      f.write(`os.getpid()`)
 
 #=== MAIN CLASS ================================================================
 
