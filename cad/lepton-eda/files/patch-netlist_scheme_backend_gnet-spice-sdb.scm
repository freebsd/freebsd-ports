--- netlist/scheme/backend/gnet-spice-sdb.scm.orig	2019-10-03 20:45:55 UTC
+++ netlist/scheme/backend/gnet-spice-sdb.scm
@@ -209,7 +209,7 @@
     (and (string-ci=? (gnetlist:get-package-attribute package "device")
                       "spice-io")
          package))
-  (filter-map spice-io? ls))
+  (filter-map spice-io? package-list))
 
 
 ;;; Given a list of spice-IO packages (refdeses), this function
