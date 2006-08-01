--- setup.py	Tue Aug  1 00:23:11 2006
+++ setup.py	Tue Aug  1 00:23:43 2006
@@ -48,11 +48,11 @@
 		#Plan text documentation.
 		(os.path.join("share","xgngeo","doc"),[os.path.join("doc","xgngeo-doc.txt")]),
 		#Localization files.
-		(os.path.join("share","xgngeo","locale","es","LC_MESSAGES"),[os.path.join("data","locale","es","LC_MESSAGES","xgngeo.mo")]), #Spanish
-		(os.path.join("share","xgngeo","locale","de","LC_MESSAGES"),[os.path.join("data","locale","de","LC_MESSAGES","xgngeo.mo")]), #German
-		(os.path.join("share","xgngeo","locale","fr","LC_MESSAGES"),[os.path.join("data","locale","fr","LC_MESSAGES","xgngeo.mo")]), #French
-		(os.path.join("share","xgngeo","locale","pl","LC_MESSAGES"),[os.path.join("data","locale","pl","LC_MESSAGES","xgngeo.mo")]), #Polish
-		(os.path.join("share","xgngeo","locale","pt_BR","LC_MESSAGES"),[os.path.join("data","locale","pt_BR","LC_MESSAGES","xgngeo.mo")]) #Portuguese of Brazil
+		(os.path.join("share","locale","es","LC_MESSAGES"),[os.path.join("data","locale","es","LC_MESSAGES","xgngeo.mo")]), #Spanish
+		(os.path.join("share","locale","de","LC_MESSAGES"),[os.path.join("data","locale","de","LC_MESSAGES","xgngeo.mo")]), #German
+		(os.path.join("share","locale","fr","LC_MESSAGES"),[os.path.join("data","locale","fr","LC_MESSAGES","xgngeo.mo")]), #French
+		(os.path.join("share","locale","pl","LC_MESSAGES"),[os.path.join("data","locale","pl","LC_MESSAGES","xgngeo.mo")]), #Polish
+		(os.path.join("share","locale","pt_BR","LC_MESSAGES"),[os.path.join("data","locale","pt_BR","LC_MESSAGES","xgngeo.mo")]) #Portuguese of Brazil
 		],
 	scripts = [os.path.join("data","script","xgngeo_startup.py")] #Startup script.
 	)
