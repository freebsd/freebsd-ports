--- lib/Util.pm.orig	Sat Feb  1 15:54:45 2003
+++ lib/Util.pm	Sat Feb  1 16:26:12 2003
@@ -67,6 +67,7 @@
 =cut
 
 sub debug {
+=port-FreeBSD sans trace
    my (@DATE) = ("Janvier","Février", "Mars","Avril", "Mai", "Juin", "Juillet","Août","Septembre", "Octobre","Novembre","Décembre");
    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);
    $year += 1900;
@@ -78,10 +79,11 @@
    $date .= "mn";
    $date .= (length($sec) > 1)?$sec:"0$sec";
    $date .= "s";
-   open (DEBUG , ">>$BASEAD/log/debug.txt") ||
+   open (DEBUG , ">>/var/log/facturier.log") ||
       &alert ("Probleme d'ouverture du fichier de debug");
    print DEBUG "$date:",@_,"\n";
    close (DEBUG);
+=cut
    return;
 }
 
