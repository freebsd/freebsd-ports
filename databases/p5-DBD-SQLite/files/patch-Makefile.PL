--- Makefile.PL.orig	Fri Aug  5 19:15:09 2005
+++ Makefile.PL	Wed Apr 12 11:13:37 2006
@@ -65,31 +65,31 @@ if ($force_local = (grep(/USE_LOCAL_SQLI
 
 # Now, check for a compatible sqlite3
 unless ($force_local) {
-    my ($dir, $file, $fh, $version);
+    my ($dir, $file, $version);
     print "Checking installed SQLite version...\n";
     if ($sqlite_inc) {
-        open($fh, '< ' . File::Spec->catfile($sqlite_inc, 'sqlite3.h'))
+        open(FH, '< ' . File::Spec->catfile($sqlite_inc, 'sqlite3.h'))
             or die "Error opening sqlite3.h in $sqlite_inc: $!";
-        while (defined($_ = <$fh>)) {
+        while (defined($_ = <FH>)) {
             if (/\#define\s+SQLITE_VERSION_NUMBER\s+(\d+)/) {
                 $version = $1;
                 last;
             }
         }
-        close($fh);
+        close(FH);
     } else {
         # Go hunting for the file (Matt: Add more dirs here as you see fit)
         for $dir ([ qw(usr include) ], [ qw(usr local include) ]) {
             $file = File::Spec->catfile('', @$dir, 'sqlite3.h');
             next unless (-f $file);
-            open($fh, "< $file") or die "Error opening $file: $!";
-            while (defined($_ = <$fh>)) {
+            open(FH, "< $file") or die "Error opening $file: $!";
+            while (defined($_ = <FH>)) {
                 if (/\#define\s+SQLITE_VERSION_NUMBER\s+(\d+)/) {
                     $version = $1;
                     last;
                 }
             }
-            close($fh);
+            close(FH);
             last if $version;
         }
     }
@@ -115,11 +115,11 @@ WriteMakefile(
     'OBJECT'        => ($force_local) ? '$(O_FILES)' : 'SQLite.o dbdimp.o',
     'INC'           => '-I. -I$(DBI_INSTARCH_DIR)' .
                        (($sqlite_inc) ? " -I$sqlite_inc" : ''),
-    $force_local ? () : ('LIBS' => '-lsqlite3'),
+    $force_local ? () : ('LIBS' => $sqlite_lib ? "-L$sqlite_lib -lsqlite3" : "-lsqlite3"),
     $sqlite_lib  ? ('dynamic_lib' => { OTHERLDFLAGS => "-L$sqlite_lib" }) : (),
     'OPTIMIZE'      => "-O2",
     'DEFINE'        => "-DNDEBUG=1 -DSQLITE_PTR_SZ=$Config{ptrsize}" .
-                       ( ($Config{d_usleep} ||
+                       ( (1 ||
                           $Config{osname} =~ m/linux/) ?
                                 " -DHAVE_USLEEP=1" : "" ) .
                        ($DBI::VERSION > 1.42 ? '' : ' -Dno_last_insert_id'),
