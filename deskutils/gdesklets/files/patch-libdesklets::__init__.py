# Many thanks to Alexander Leidinger <netchild@FreeBSD.org> for
# help and create those patches.

--- libdesklets/__init__.py.orig	Fri Oct 17 23:16:45 2003
+++ libdesklets/__init__.py	Fri Oct 17 23:17:09 2003
@@ -51,11 +51,10 @@
 from Network import Network
 from Sys import Sys
 
-
+sys = Sys()
 convert = Convert()
 cpu = CPU()
 disk = Disk()
 memory = Memory()
 net = Network()
-sys = Sys()
 print "INIT libdesklets (should happen only once)"
