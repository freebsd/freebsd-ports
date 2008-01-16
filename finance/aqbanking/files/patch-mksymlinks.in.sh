--- mksymlinks.sh.in.orig	Mon Jan 14 21:41:07 2008
+++ mksymlinks.sh.in	Mon Jan 14 21:43:08 2008
@@ -23,7 +23,7 @@
 # functions
 #
 
-function symlinkFolder() {
+symlinkFolder() {
   local dfiles
   local src
   local dst
