--- Makefile.PL-orig	2014-07-25 15:03:49.000000000 +0200
+++ Makefile.PL	2014-07-25 15:04:03.000000000 +0200
@@ -206,7 +206,7 @@
     }
     # see rt 46944 for why the following was suggested to be commented
     # out which I rejected as PERL_MM_USE_DEFAULT can be used
-    prompt("Press return to continue...");
+#    prompt("Press return to continue...");
 }
 print "Overriding ODBC Directory with command line option: $opt_o\n"
     if $opt_o ;
