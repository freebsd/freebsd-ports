--- hhc2html.pl.orig	Thu May  8 13:05:31 2003
+++ hhc2html.pl	Thu May  8 13:05:39 2003
@@ -40,7 +40,7 @@
     $name="";
     $local="";
     OBJECT: while(<>){
-	last OBJECT if /<\/object>/i && print "<a href=$local>$name</a></dev>";
+	last OBJECT if /<\/object>/i && print "<a href=$local>$name</a></div>";
 	if( /(.*)($param)(.*)/i ){
 	    $pre=$1; $_=$2; $post=$3;
 	    print $pre,$post;
