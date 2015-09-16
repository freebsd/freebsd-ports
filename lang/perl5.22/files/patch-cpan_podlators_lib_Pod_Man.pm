--- cpan/podlators/lib/Pod/Man.pm.orig	2015-04-15 07:47:18 UTC
+++ cpan/podlators/lib/Pod/Man.pm
@@ -876,25 +876,42 @@ sub devise_title {
 }
 
 # Determine the modification date and return that, properly formatted in ISO
-# format.  If we can't get the modification date of the input, instead use the
-# current time.  Pod::Simple returns a completely unuseful stringified file
-# handle as the source_filename for input from a file handle, so we have to
-# deal with that as well.
+# format.
+#
+# If POD_MAN_DATE is set, that overrides anything else.  This can be used for
+# reproducible generation of the same file even if the input file timestamps
+# are unpredictable or the POD coms from standard input.
+#
+# Otherwise, use the modification date of the input if we can stat it.  Be
+# aware that Pod::Simple returns the stringification of the file handle as
+# source_filename for input from a file handle, so we'll stat some random ref
+# string in that case.  If that fails, instead use the current time.
+#
+# $self - Pod::Man object, used to get the source file
+#
+# Returns: YYYY-MM-DD date suitable for the left-hand footer
 sub devise_date {
     my ($self) = @_;
+
+    # If POD_MAN_DATE is set, always use it.
+    if ($ENV{POD_MAN_DATE}) {
+        return $ENV{POD_MAN_DATE};
+    }
+
+    # Otherwise, get the input filename and try to stat it.  If that fails,
+    # use the current time.
     my $input = $self->source_filename;
     my $time;
     if ($input) {
-        $time = (stat $input)[9] || time;
+        $time = (stat($input))[9] || time();
     } else {
-        $time = time;
+        $time = time();
     }
 
-    # Can't use POSIX::strftime(), which uses Fcntl, because MakeMaker
-    # uses this and it has to work in the core which can't load dynamic
-    # libraries.
-    my ($year, $month, $day) = (localtime $time)[5,4,3];
-    return sprintf ("%04d-%02d-%02d", $year + 1900, $month + 1, $day);
+    # Can't use POSIX::strftime(), which uses Fcntl, because MakeMaker uses
+    # this and it has to work in the core which can't load dynamic libraries.
+    my ($year, $month, $day) = (localtime($time))[5,4,3];
+    return sprintf("%04d-%02d-%02d", $year + 1900, $month + 1, $day);
 }
 
 # Print out the preamble and the title.  The meaning of the arguments to .TH
@@ -1632,6 +1649,15 @@ argument.
 Sets the centered page header to use instead of "User Contributed Perl
 Documentation".
 
+=item date
+
+Sets the left-hand footer.  If this option is not set, the contents of the
+environment variable POD_MAN_DATE, if set, will be used.  Failing that,
+the modification date of the input file will be used, or the current time
+if stat() can't find that file (which will be the case if the input is
+from C<STDIN>).  If obtained from the file modification date or the
+current time, he date will be formatted as C<YYYY-MM-DD>.
+
 =item errors
 
 How to report errors.  C<die> says to throw an exception on any POD
@@ -1642,13 +1668,6 @@ POD errors entirely, as much as possible
 
 The default is C<pod>.
 
-=item date
-
-Sets the left-hand footer.  By default, the modification date of the input
-file will be used, or the current date if stat() can't find that file (the
-case if the input is from C<STDIN>), and the date will be formatted as
-C<YYYY-MM-DD>.
-
 =item fixed
 
 The fixed-width font to use for verbatim text and code.  Defaults to
@@ -1810,6 +1829,20 @@ option was set to C<die>.
 
 =back
 
+=head1 ENVIRONMENT
+
+=over 4
+
+=item POD_MAN_DATE
+
+If set, this will be used as the value of the left-hand footer unless the
+C<date> option is explicitly set, overriding the timestamp of the input
+file or the current time.  This is primarily useful to ensure reproducible
+builds of the same output file given the same souce and Pod::Man version,
+even when file timestamps may not be consistent.
+
+=back
+
 =head1 BUGS
 
 Encoding handling assumes that PerlIO is available and does not work
