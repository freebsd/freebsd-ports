Index: make.sh
===================================================================
RCS file: /cvsroot/sbcl/sbcl/make.sh,v
retrieving revision 1.47
diff -u -r1.47 make.sh
--- make.sh	5 Apr 2006 07:46:59 -0000	1.47
+++ make.sh	28 May 2006 05:24:20 -0000
@@ -77,7 +77,7 @@
 sh make-config.sh
 
 # Enforce the source policy for no bogus whitespace
-tools-for-build/canonicalize-whitespace
+#tools-for-build/canonicalize-whitespace
 
 # The make-host-*.sh scripts are run on the cross-compilation host,
 # and the make-target-*.sh scripts are run on the target machine. In
