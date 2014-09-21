--- lib/PatchReader/Raw.pm.orig	2014-09-20 06:54:09 UTC
+++ lib/PatchReader/Raw.pm
@@ -41,7 +41,7 @@
   return if $line =~ /^\?/;
 
   # patch header parsing
-  if ($line =~ /^---\s*([\S ]+)\s*\t([^\t\r\n]*)\s*(\S*)/) {
+  if ($line =~ /^---\s+([\S ]+)\s*?(?:\t([^\t\r\n]*)\s*(\S*))?/) {
     $this->_maybe_end_file();
 
     if ($1 eq "/dev/null") {
@@ -54,9 +54,11 @@
 
     $this->{IN_HEADER} = 1;
 
-  } elsif ($line =~ /^\+\+\+\s*([\S ]+)\s*\t([^\t\r\n]*)(\S*)/) {
+  } elsif ($line =~ /^\+\+\+\s+([\S ]+)\s*?(?:\t([^\t\r\n]*)(\S*))?/) {
     if ($1 eq "/dev/null") {
       $this->{FILE_STATE}{is_remove} = 1;
+    } else {
+      $this->{FILE_STATE}{filename} = $1;
     }
     $this->{FILE_STATE}{new_date_str} = $2;
     $this->{FILE_STATE}{new_revision} = $3 if $3;
