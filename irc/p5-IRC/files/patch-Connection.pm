--- Connection.pm.orig	Sun Jul  1 14:50:50 2001
+++ Connection.pm	Tue Nov 27 09:31:39 2001
@@ -1112,7 +1112,7 @@
 		 /x)                      # That ought to do it for now...
 	{
 	    $line = substr $line, 1 if $line =~ /^:/;
-	    ($from, $line) = split ":", $line, 2;
+	    ($from, $line) = $line =~ m/^(\S+\s.*?):(.*)$/;
 	    ($from, $type, @stuff) = split /\s+/, $from;
 	    $type = lc $type;
 	    
