# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/__init__.py.orig	Mon Sep 22 13:15:25 2003
+++ libdesklets/__init__.py	Mon Sep 22 13:15:30 2003
@@ -52,10 +52,10 @@
 from Sys import Sys
 
 
+sys = Sys()
 convert = Convert()
 cpu = CPU()
 disk = Disk()
 memory = Memory()
 net = Network()
-sys = Sys()
 print "INIT libdesklets (should happen only once)"
