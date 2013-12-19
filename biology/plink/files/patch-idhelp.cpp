--- idhelp.cpp.orig	2013-11-16 17:11:42.000000000 +0100
+++ idhelp.cpp	2013-11-16 17:12:53.000000000 +0100
@@ -772,12 +772,12 @@
       for (int j = 0 ; j < jointField.size(); j++ )
 	{
 	  set<IDField*> & jf = jointField[j];
-	  set<IDField*>::iterator j = jf.begin();
+	  set<IDField*>::iterator jfit = jf.begin();
 	  PP->printLOG(" { ");
-	  while ( j != jf.end() )
+	  while ( jfit != jf.end() )
 	    {
-	      PP->printLOG( (*j)->name + " " );
-	      ++j;
+	      PP->printLOG( (*jfit)->name + " " );
+	      ++jfit;
 	    }
 	  PP->printLOG(" }");
 	}
