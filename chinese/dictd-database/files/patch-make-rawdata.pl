--- make-rawdata.pl.orig	Fri Jul 19 02:04:15 2002
+++ make-rawdata.pl	Fri Jul 19 02:04:50 2002
@@ -111,7 +111,7 @@
 
 sub cedict {
 
-	open ( FILE, "data/cedict.utf8") ;
+	open ( FILE, "data/cedict.b5") ;
 	@RawData = <FILE> ;
 	close (FILE) ;
 
@@ -121,12 +121,12 @@
 	print TXT <<__END ;
 %h 00-database-info
 %d 
-English to Chinese Dictionary º~­^¦r¨å
+Chinese to English Dictionary º~­^¦r¨å
 CEDICT January 17, 2001; Copyright 2000-01
 __END
 
 	foreach $data (@RawData) {
-                $data =~ s/(.*) \[(.*)\] \/(.*)\//%h $1\n%d\n$3\n/g ;
+                $data =~ s/(.*) \[(.*)\] \/(.*)\//%h $1\n%d\n[$2]\n$3\n/g ;
                 $data =~ s/\//\n/g ;
                 print TXT $data ;
         }
