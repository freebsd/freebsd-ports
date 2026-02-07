--- unoidl/source/sourceprovider-parser.y.orig	2022-01-26 14:35:29 UTC
+++ unoidl/source/sourceprovider-parser.y
@@ -10,7 +10,7 @@
 /*TODO: check Exception, RuntimeException, XInterface defns */
 
 %locations
-%pure-parser
+%define api.pure full
 
 %{
 
