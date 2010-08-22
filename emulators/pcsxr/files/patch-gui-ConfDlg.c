--- gui/ConfDlg.c.orig	2010-06-03 07:59:39.428023393 +0000
+++ gui/ConfDlg.c	2010-06-03 08:01:49.836121070 +0000
@@ -632,7 +632,7 @@
 		}
 
 		PSE_getLibType = (PSEgetLibType)dlsym(Handle, "PSEgetLibType");
-		if (dlerror() != NULL) {
+		if (PSE_getLibType == NULL) {
 			if (strstr(linkname, "gpu") != NULL) type = PSE_LT_GPU;
 			else if (strstr(linkname, "cdr") != NULL) type = PSE_LT_CDR;
 			else if (strstr(linkname, "spu") != NULL) type = PSE_LT_SPU;
@@ -642,10 +642,10 @@
 		else type = PSE_getLibType();
 
 		PSE_getLibName = (PSEgetLibName) dlsym(Handle, "PSEgetLibName");
-		if (dlerror() == NULL) {
+		if (PSE_getLibName != NULL) {
 			sprintf(name, "%s", PSE_getLibName());
 			PSE_getLibVersion = (PSEgetLibVersion) dlsym(Handle, "PSEgetLibVersion");
-			if (dlerror() == NULL) {
+			if (PSE_getLibVersion != NULL) {
 				char ver[32];
 
 				v = PSE_getLibVersion();
@@ -720,17 +720,17 @@
 			if (Handle == NULL) continue;
 
 			PSE_getLibType = (PSEgetLibType) dlsym(Handle, "PSEgetLibType");
-			if (dlerror() != NULL) {
+			if (PSE_getLibType == NULL) {
 				if (strstr(plugin, "net") != NULL) type = PSE_LT_NET;
 				else continue;
 			}
 			else type = PSE_getLibType();
 
 			PSE_getLibName = (PSEgetLibName) dlsym(Handle, "PSEgetLibName");
-			if (dlerror() == NULL) {
+			if (PSE_getLibName != NULL) {
 				sprintf(name, "%s", PSE_getLibName());
 				PSE_getLibVersion = (PSEgetLibVersion) dlsym(Handle, "PSEgetLibVersion");
-				if (dlerror() == NULL) {
+				if (PSE_getLibVersion != NULL) {
 					char ver[32];
 
 					v = PSE_getLibVersion();
