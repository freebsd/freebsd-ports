--- ./ripit.pl.orig	2009-02-02 19:23:52.000000000 +0000
+++ ./ripit.pl	2009-02-02 19:24:58.000000000 +0000
@@ -3398,7 +3398,7 @@
 
    # If Lame is not used, don't die if ID3v2-tag is not compliant.
    if($lameflag == 0) {
-      unless(log_system("lame --genre-list | grep -i \" $genre\$\" > /dev/null ")) {
+      unless(log_system("lame --genre-list 2>&1 | grep -i \" $genre\$\" > /dev/null ")) {
          print "Genre $genre is not ID3v2 compliant!\n"
             if($verbose >= 1);
          print "I continue anyway!\n\n" if($verbose >= 1);
@@ -3417,7 +3417,7 @@
 
    # Check if (similar) genre exists. Enter a new one with interaction,
    # or take the default one.
-   while(!log_system("lame --genre-list | grep -i \"$genre\" > /dev/null ")) {
+   while(!log_system("lame --genre-list 2>&1 | grep -i \"$genre\" > /dev/null ")) {
       print "Genre $genre is not ID3v2 compliant!\n" if($verbose >= 1);
       if($interaction == 1) {
          print "Use \"lame --genre-list\" to get a list!\n";
@@ -3437,7 +3437,7 @@
       return;
    }
    elsif($genre =~ /^\d+$/) {
-      $genre = `lame --genre-list | grep -i \' $genre \'`;
+      $genre = `lame --genre-list 2>&1 | grep -i \' $genre \'`;
       chomp $genre;
    }
    else {
@@ -3449,10 +3449,10 @@
       # "pop-like" genres!
       # There will be a linebreak, if multiple possibilities found.
       my $ogenre = $genre;
-      $genre = `lame --genre-list | grep -i \'$genre\'`;
+      $genre = `lame --genre-list 2>&1 | grep -i \'$genre\'`;
       chomp $genre;
       # Second we want THE original genre, if it precisly exists.
-      my $testgenre = `lame --genre-list | grep -i \'\^... $ogenre\$\'`;
+      my $testgenre = `lame --genre-list 2>&1 | grep -i \'\^... $ogenre\$\'`;
       chomp $testgenre;
       $genre = $testgenre if($testgenre);
       # If we still have several genres:
