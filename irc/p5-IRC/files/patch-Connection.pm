--- Connection.pm.orig	Tue May 30 07:12:02 2000
+++ Connection.pm	Wed Jun 13 17:01:06 2001
@@ -1101,7 +1101,7 @@
 		 /x)                      # That ought to do it for now...
 	{
 	    $line = substr $line, 1 if $line =~ /^:/;
-	    ($from, $line) = split ":", $line, 2;
+	    ($from, $line) = $line =~ m/^(.*):(.*?)$/;
 	    ($from, $type, @stuff) = split /\s+/, $from;
 	    $type = lc $type;
 	    
