Index: egg/canna.el
diff -u egg/canna.el.orig egg/canna.el
--- egg/canna.el.orig	Thu Feb 24 00:16:28 2005
+++ egg/canna.el	Thu Feb 24 00:27:33 2005
@@ -53,7 +53,7 @@
   "Group Name on CANNA server"
   :group 'canna :type 'string)
 
-(defcustom egg-canna-icanna-path "icanna"
+(defcustom egg-canna-icanna-path "egg-helper"
   "path of canna unix domain connection helper program"
   :group 'canna :type 'file)
 
