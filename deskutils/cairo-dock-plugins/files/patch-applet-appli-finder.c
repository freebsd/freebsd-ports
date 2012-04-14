--- Scooby-Do/src/applet-appli-finder.c.orig	2012-03-10 14:50:21.113987701 +0200
+++ Scooby-Do/src/applet-appli-finder.c	2012-03-10 14:50:35.394070505 +0200
@@ -70,7 +70,7 @@
 	cd_debug ("la liste des applis a change dans %s!\n", cURI);
 	// on reconstruit la liste des applis.
 	cd_do_reset_applications_list ();
-	_browse_dir ("/usr/share/applications");  // oui c'est bourrin, ca ne doit pas arriver tres souvent?
+	_browse_dir ("/usr/local/share/applications");  // oui c'est bourrin, ca ne doit pas arriver tres souvent?
 	myData.pApplications = g_list_sort (myData.pApplications, (GCompareFunc) _compare_appli);
 }
 static void _browse_dir (const gchar *cDirPath)
@@ -210,7 +210,7 @@
 	//\_______________ On liste les applis.
 	if (myData.pApplications == NULL)  // on n'a pas encore liste les applications, on le fait maintenant.
 	{
-		_browse_dir ("/usr/share/applications");
+		_browse_dir ("/usr/local/share/applications");
 		myData.pApplications = g_list_sort (myData.pApplications, (GCompareFunc) _compare_appli);  // on parcourt tout d'un coup (plutot que par exemple seulement les .desktop correspondant a la 1ere lettre car il y'a les sous-rep a parcourir, donc il faut de toute maniere se farcir la totale; de plus la commande peut differer du nom du .desktop.
 	}
 	
