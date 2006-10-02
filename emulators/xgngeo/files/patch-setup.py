--- setup.py	Sun Oct  1 20:57:22 2006
+++ setup.py	Sun Oct  1 20:57:44 2006
@@ -55,19 +55,19 @@
 		(os.path.join("share", "applications"), [os.path.join("data", "misc", "xgngeo.desktop")]),
 		#Localization files.
 		#Spanish
-		(os.path.join("share", "xgngeo", "locale", "es", "LC_MESSAGES"),
+		(os.path.join("share", "locale", "es", "LC_MESSAGES"),
 			[os.path.join("data", "locale", "es", "LC_MESSAGES", "xgngeo.mo")]),
 		#German
-		(os.path.join("share", "xgngeo", "locale", "de", "LC_MESSAGES"),
+		(os.path.join("share", "locale", "de", "LC_MESSAGES"),
 			[os.path.join("data", "locale", "de", "LC_MESSAGES", "xgngeo.mo")]),
 		#French
-		(os.path.join("share", "xgngeo", "locale", "fr", "LC_MESSAGES"),
+		(os.path.join("share", "locale", "fr", "LC_MESSAGES"),
 			[os.path.join("data", "locale", "fr", "LC_MESSAGES", "xgngeo.mo")]),
 		#Polish
-		(os.path.join("share", "xgngeo", "locale", "pl", "LC_MESSAGES"),
+		(os.path.join("share", "locale", "pl", "LC_MESSAGES"),
 			[os.path.join("data", "locale", "pl", "LC_MESSAGES", "xgngeo.mo")]),
 		#Portuguese of Brazil
-		(os.path.join("share", "xgngeo", "locale", "pt_BR", "LC_MESSAGES"),
+		(os.path.join("share", "locale", "pt_BR", "LC_MESSAGES"),
 			[os.path.join("data", "locale", "pt_BR", "LC_MESSAGES", "xgngeo.mo")])
 		]
 	)
