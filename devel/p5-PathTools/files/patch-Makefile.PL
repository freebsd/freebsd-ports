
$FreeBSD$

--- Makefile.PL.orig	Sun Jun 25 19:02:43 2000
+++ Makefile.PL	Thu Apr 25 15:20:32 2002
@@ -7,7 +7,7 @@
     'LIBS'          => [''],   # e.g., '-lm' 
     'DEFINE'        => '',     # e.g., '-DHAVE_SOMETHING' 
     'INC'           => '',     # e.g., '-I/usr/include/other' 
-    'INSTALLDIRS'   => 'perl', # 'perl' makes it replace std modules
+#    'INSTALLDIRS'   => 'perl', # 'perl' makes it replace std modules
 #    'PM'	=> {'Spec.pm'	=> '$(INST_LIBDIR)/File/Spec.pm',
 #    			'OS2.pm'	=> '$(INST_LIBDIR)/File/Spec/OS2.pm',
 #    			'Win32.pm'	=> '$(INST_LIBDIR)/File/Spec/Win32.pm',
