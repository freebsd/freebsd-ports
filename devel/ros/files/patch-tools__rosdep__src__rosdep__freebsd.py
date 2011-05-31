--- ./tools/rosdep/src/rosdep/freebsd.py.orig	2011-02-24 23:45:21.000000000 +0100
+++ ./tools/rosdep/src/rosdep/freebsd.py	2011-03-20 15:21:34.000000000 +0100
@@ -44,11 +44,11 @@
     if p == "gtk20":
         portname = "gtk-2.\*"
     elif p == "py-gtk2":
-        portname = "py26-gtk-2.\*"
+        portname = "py27-gtk-2.\*"
     elif p[:9] in ["autoconf2", "automake1"]:
         portname = p[:8] + "-" + p[8] + "." + p[9:] + "\*"
     elif p[:3] == "py-":
-        portname = "py26-" + p[3:] + "\*"
+        portname = "py27-" + p[3:] + "\*"
     else:
         portname = p + "-\*"
     pop = subprocess.Popen("/usr/sbin/pkg_info -qE " + portname, shell=True)
