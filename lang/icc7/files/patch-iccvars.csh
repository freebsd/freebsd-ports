--- opt/intel/compiler50/ia32/bin/iccvars.csh.orig	Sun Mar 31 11:14:54 2002
+++ opt/intel/compiler50/ia32/bin/iccvars.csh	Sun Mar 31 11:16:11 2002
@@ -1,4 +1,4 @@
-#! /bin/tcsh
+#! /bin/csh
 if ! ($?IA32ROOT) then
     setenv IA32_SAVE_PATH $PATH
     if ($?LD_LIBRARY_PATH) then
@@ -24,6 +24,6 @@
     setenv LD_LIBRARY_PATH $IA32ROOT/lib:$IA32_SAVE_LD_LIBRARY_PATH
     endif
 
-setenv INTEL_FLEXLM_LICENSE=<INSTALLDIR>/licenses
+setenv INTEL_FLEXLM_LICENSE <INSTALLDIR>/licenses
 
 
