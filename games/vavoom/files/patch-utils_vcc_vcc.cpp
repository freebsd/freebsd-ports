--- utils/vcc/vcc.cpp.orig	2017-06-04 09:44:06.817573000 +0200
+++ utils/vcc/vcc.cpp	2017-06-04 10:05:59.278454000 +0200
@@ -122,7 +122,7 @@
 	}
 	catch (VException& e)
 	{
-		FatalError(e.What());
+		FatalError("%s", e.What());
 	}
 	return 0;
 }
