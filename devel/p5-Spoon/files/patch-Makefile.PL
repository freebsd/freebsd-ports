--- Makefile.PL.orig	Wed Apr  6 10:07:55 2005
+++ Makefile.PL	Wed Apr  6 10:07:42 2005
@@ -0,0 +1,18 @@
+use inc::Module::Install;
+
+name('Spoon');
+author('Brian Ingerson <ingy@cpan.org>');
+abstract('Out of the Cutlery Drawer');
+license('perl');
+version_from('lib/Spoon.pm');
+
+requires(qw(
+        perl 5.6.1
+	Spiffy 0.22
+	IO::All 0.32
+	Template 2.10
+));
+
+clean_files('t/tmp', 't/output');
+
+&WriteAll();
