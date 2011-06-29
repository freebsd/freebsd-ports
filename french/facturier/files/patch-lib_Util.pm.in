--- lib/Util.pm.orig	Mon Sep 22 11:39:16 2003
+++ lib/Util.pm	Mon Oct 13 23:27:53 2003
@@ -67,6 +67,7 @@
 =cut
 
 sub debug {
+=port-FreeBSD sans trace
    my (@DATE) = ("Janvier","Février", "Mars","Avril", "Mai", "Juin", "Juillet","Août","Septembre", "Octobre","Novembre","Décembre");
    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);
    $year += 1900;
@@ -82,23 +83,24 @@
 
    my ($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,
    $atime,$mtime,$ctime,$blksize,$blocks)
-                = stat("$BASEAD/log/debug.txt");
+                = stat("/var/log/facturier.log");
    if ( $size >= $LOGSIZE )
        {
         for ( my $i=$MAXLOG;$i>1;$i--)
          {
-          unlink "$BASEAD/log/debug$i.txt";
+          unlink "/var/log/facturier$i.log";
           my $j=$i-1;
-          rename ("$BASEAD/log/debug$j.txt","$BASEAD/log/debug$i.txt");
+          rename ("/var/log/facturier$j.log","/var/log/facturier$i.log");
          }
-        rename ( "$BASEAD/log/debug.txt", "$BASEAD/log/debug1.txt" );
+        rename ( "/var/log/facturier.log", "/var/log/facturier1.log" );
        }
    
    #############
-   open (DEBUG , ">>$BASEAD/log/debug.txt") ||
+   open (DEBUG , ">>/var/log/facturier.log") ||
       &alert ("Probleme d'ouverture du fichier de debug");
    print DEBUG "$date:",@_,"\n";
    close (DEBUG);
+=cut
    return;
 }
 
