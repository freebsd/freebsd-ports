--- ./rpython/config/support.py~	2013-12-16 12:34:17.000000000 +0200
+++ ./rpython/config/support.py	2013-12-16 12:33:52.000000000 +0200
@@ -8,7 +8,9 @@
     if os.environ.get('MAKEFLAGS'):
         return 1    # don't override MAKEFLAGS.  This will call 'make' without any '-j' option
     if sys.platform == 'darwin':
-        return darwin_get_cpu_count()
+        return sysctl_get_cpu_count('/usr/sbin/sysctl')
+    elif sys.platform.startswith('freebsd'):
+        return sysctl_get_cpu_count('/sbin/sysctl')
     elif not sys.platform.startswith('linux'):
         return 1    # implement me
     try:
@@ -26,11 +28,10 @@
     except:
         return 1 # we really don't want to explode here, at worst we have 1
 
-def darwin_get_cpu_count(cmd = "/usr/sbin/sysctl hw.ncpu"):
+def sysctl_get_cpu_count(cmd, name='hw.ncpu'):
     try:
-        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
-        # 'hw.ncpu: 20'
-        count = proc.communicate()[0].rstrip()[8:]
+        proc = subprocess.Popen([cmd, '-n', name], stdout=subprocess.PIPE)
+        count = proc.communicate()[0]
         return int(count)
     except (OSError, ValueError):
         return 1
