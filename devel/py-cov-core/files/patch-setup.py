Based on debian patch:

Author: Barry Warsaw <barry@debian.org>
Patch-Name: pth-installation-path
Subject: Calculate the correct .pth path

 cov-core wants to install the file init_cov_core.pth so that cov_core_init
 will be imported and initialized automatically for subprocess coverage, if
 the environment variable COV_CORE_SOURCE is set (which e.g. nose does
 automatically).  However the upstream setup.py tries to install this file
 directly into /usr/lib/pythonX.Y/{site,dist}-packages, which clearly doesn't
 work when building the package.  This patch hard codes the .pth path for a
 location within the build directory.  dh_python{2,3} does the rest.
Forwarded: not-needed

--- setup.py
+++ setup.py
@@ -48,23 +48,6 @@
                               'Topic :: Software Development :: Testing'])
 
 if sys.argv[1] in ('install', 'develop'):
-    for path in sys.path:
-        if (path.endswith('site-packages')) or (path.endswith('dist-packages')
-                                                and 'local' in path):
-            path = os.path.join(path, PTH_FILE_NAME)
-            try:
-                pth_file = open(path, 'w')
-                pth_file.write(PTH_FILE)
-                pth_file.close()
-                sys.stdout.write('\nWrote pth file for subprocess '
-                                 'measurement to %s\n' % path)
-                break
-            except Exception:
-                sys.stdout.write('\nFailed to write pth file for subprocess '
-                                 'measurement to %s\n' % path)
-                sys.stdout.write(PTH_FILE_FAILURE)
-                break
-    else:
-        sys.stdout.write('\nFailed to find site-packages or dist-packages '
-                         'dir to put pth file in.\n')
-        sys.stdout.write(PTH_FILE_FAILURE)
+    pth_path = PTH_FILE_NAME
+    with open(pth_path, 'w') as fp:
+        fp.write(PTH_FILE)
