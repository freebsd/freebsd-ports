--- sets.cpp.orig	2013-11-16 17:06:29.000000000 +0100
+++ sets.cpp	2013-11-16 17:07:12.000000000 +0100
@@ -768,11 +768,11 @@
       //////////////////////////////////////////////
       // Reset original missing status
 
-      vector<Individual*>::iterator i = PP->sample.begin();
-      while ( i != PP->sample.end() )
+      vector<Individual*>::iterator ipp = PP->sample.begin();
+      while ( ipp != PP->sample.end() )
 	{
-	  (*i)->missing = (*i)->flag;
-	  ++i;
+	  (*ipp)->missing = (*ipp)->flag;
+	  ++ipp;
 	}
 
       ////////////////////////////////////////////////
