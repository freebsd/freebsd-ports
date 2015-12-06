--- apps/tqsl.cpp.orig	2015-10-21 17:26:38 UTC
+++ apps/tqsl.cpp
@@ -4680,7 +4680,7 @@ QSLApp::OnInit() {
 	for (int i = 1; i < argc; i++) {
 		origCommandLine += wxT(" ");
 		origCommandLine += argv[i];
-		if (argv[i] && (argv[i][0] == wxT('-') || argv[i][0] == wxT('/')))
+		if ((argv[i][0] == wxT('-') || argv[i][0] == wxT('/')))
 			if (wxIsalpha(argv[i][1]) && wxIsupper(argv[i][1]))
 				argv[i][1] = wxTolower(argv[i][1]);
 	}
