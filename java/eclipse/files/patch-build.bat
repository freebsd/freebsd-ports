--- build.bat.orig	Mon Jun 27 21:55:26 2005
+++ build.bat	Sun Jul 17 18:21:31 2005
@@ -44,6 +44,9 @@
 if %os%-%ws%-%arch%==qnx-photon-x86 goto run
 if %os%-%ws%-%arch%==hpux-motif-ia64_32 goto run
 if %os%-%ws%-%arch%==macosx-carbon-ppc goto run
+if %os%-%ws%-%arch%==freebsd-motif-x86 goto run
+if %os%-%ws%-%arch%==freebsd-gtk-x86 goto run
+if %os%-%ws%-%arch%==freebsd-gtk-amd64 goto run
 
 ECHO The ws os arch combination entered is not valid.
 goto end
