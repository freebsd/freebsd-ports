--- cvsweb.cgi.orig	2005-09-25 20:28:51 UTC
+++ cvsweb.cgi
@@ -2951,7 +2951,7 @@ sub printLog($$$;$$)
   print "<br />\n";
 
   print '<i>';
-  if (defined @mytz) {
+  if (@mytz) {
     my ($est) = $mytz[(localtime($date{$_}))[8]];
     print scalar localtime($date{$_}), " $est</i> (";
   } else {
