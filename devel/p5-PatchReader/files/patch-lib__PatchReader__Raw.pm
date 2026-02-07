--- lib/PatchReader/Raw.pm.orig	2015-02-19 16:02:48 UTC
+++ lib/PatchReader/Raw.pm
@@ -40,8 +40,25 @@ sub next_line {
 
   return if $line =~ /^\?/;
 
+  # FreeBSD bug #197607 - svn property changes are
+  # displayed as line additions in Bugzilla. We'll
+  # just ignore the whole property section.
+  if ($this->{in_prop} == 1) {
+      if ($line =~ /^Index:\s*([\S ]+)/) {
+          # End of property changes, continue normally.
+          $this->{in_prop} = 0;
+      } else {
+          # Ignore property lines
+          return;
+      }
+  } elsif ($line =~ /^Property changes on:.*$/) {
+      # SVN property changes, skip everything until the next index...
+      $this->{in_prop} = 1;
+      return;
+  }
+
   # patch header parsing
-  if ($line =~ /^---\s*([\S ]+)\s*\t([^\t\r\n]*)\s*(\S*)/) {
+  if ($line =~ /^---\s+([\S ]+)\s*?(?:\t([^\t\r\n]*)\s*(\S*))?/) {
     $this->_maybe_end_file();
 
     if ($1 eq "/dev/null") {
@@ -54,9 +71,11 @@ sub next_line {
 
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
