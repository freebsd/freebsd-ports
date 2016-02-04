--- setup.py.orig	2011-05-13 22:16:32 UTC
+++ setup.py
@@ -7,17 +7,14 @@ import os
 sys.path.insert(0, 'src')
 from phpsh import __version__
 
-if len(sys.argv) > 1 and sys.argv[1] == "build":
-    build_root = os.path.dirname(os.path.realpath(__file__))
-    make_dir = os.path.join(build_root, "src/xdebug-clients/geben")
-    p = Popen(["make", "-C", make_dir])
-    os.waitpid(p.pid, 0)
+### EMACS:if len(sys.argv) > 1 and sys.argv[1] == "build":
+### EMACS:    build_root = os.path.dirname(os.path.realpath(__file__))
+### EMACS:    make_dir = os.path.join(build_root, "src/xdebug-clients/geben")
+### EMACS:    p = Popen(["gmake", "-C", make_dir])
+### EMACS:    os.waitpid(p.pid, 0)
 
 # something better than this?
-if os.getenv("USER") == "root":
-    config_dir = "/etc/phpsh"
-else:
-    config_dir = os.getenv("HOME") + "/.phpsh"
+config_dir = "%%ETCDIR%%"
 
 setup(
     name="phpsh",
@@ -33,7 +30,7 @@ setup(
                             "xdebug-clients/geben/LICENSE",
                             "xdebug-clients/geben/Makefile",
                             "xdebug-clients/geben/geben.el",
-                            "xdebug-clients/geben/geben.elc",
+### EMACS:                            "xdebug-clients/geben/geben.elc",
                             "xdebug-clients/geben/help",
                             "xdebug-clients/geben/tree-widget/geben/*.png"]},
     scripts=["src/phpsh", "src/dbgp-phpsh.py"],
