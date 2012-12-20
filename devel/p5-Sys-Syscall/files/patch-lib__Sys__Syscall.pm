--- lib/Sys/Syscall.pm.orig	2010-04-18 17:51:10.000000000 -0800
+++ lib/Sys/Syscall.pm	2012-04-09 08:39:07.000000000 -0800
@@ -2,7 +2,7 @@
 
 package Sys::Syscall;
 use strict;
-use POSIX qw(ENOSYS SEEK_CUR);
+use POSIX qw(ENOSYS EAGAIN SEEK_CUR);
 
 require Exporter;
 use vars qw(@ISA @EXPORT_OK %EXPORT_TAGS $VERSION);
@@ -180,12 +180,14 @@
                      0,           # struct sf_hdtr *hdtr
                      $sbytes_buf, # off_t *sbytes
                      0);          # flags
-    return $rv if $rv < 0;
+    return $rv if $rv < 0 && $! != EAGAIN;
 
 
-    my $set = unpack("L", $sbytes_buf);
-    POSIX::lseek($_[1]+0, SEEK_CUR, $set);
-    return $set;
+    if (my $set = unpack("L", $sbytes_buf)) {
+	    POSIX::lseek($_[1]+0, $set, SEEK_CUR);
+	    return $set;
+    }
+    return $rv < 0 ? $rv : 0;
 }
 
 
