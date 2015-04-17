--- Makefile.PL.orig	2013-12-17 09:40:52 UTC
+++ Makefile.PL
@@ -206,7 +206,7 @@ EOT
     }
     # see rt 46944 for why the following was suggested to be commented
     # out which I rejected as PERL_MM_USE_DEFAULT can be used
-    prompt("Press return to continue...");
+#    prompt("Press return to continue...");
 }
 print "Overriding ODBC Directory with command line option: $opt_o\n"
     if $opt_o ;
