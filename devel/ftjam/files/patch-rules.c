--- rules.c.orig	2014-08-07 15:29:24.000000000 +0200
+++ rules.c	2014-08-07 15:29:43.000000000 +0200
@@ -185,8 +185,6 @@
 	TARGETS	*chain,
 	TARGETS	*targets )
 {
-	TARGETS *c;
-
 	if( !targets )
 	    return chain;
 	else if( !chain )
@@ -297,7 +295,7 @@
 SETTINGS *
 copysettings( SETTINGS *from )
 {
-	SETTINGS *head = 0, *v;
+	SETTINGS *head = 0;
 
 	for( ; from; from = from->next )
 	{
