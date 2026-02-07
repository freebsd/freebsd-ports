--- Makefile.PL.orig	2010-03-21 23:29:00.000000000 +0800
--- Makefile.PL	2015-01-03 03:18:10.000000000 +0800
@@ -2,6 +2,11 @@
 use warnings;
 use Inline::MakeMaker;
 
+sub MY::libscan {
+	return if ($_[1] eq 'USB.pm' or $_[1] eq 'lib/Device/dump_usb.pl');
+	return $_[1];
+}
+
 if($^O eq 'MSWin32')
 {
     if(!$ENV{LIBUSB_LIBDIR} or !$ENV{LIBUSB_INCDIR})
