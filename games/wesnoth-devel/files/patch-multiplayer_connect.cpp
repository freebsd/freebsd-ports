--- src/multiplayer_connect.cpp.orig	2008-09-07 18:16:37.000000000 -0700
+++ src/multiplayer_connect.cpp	2008-09-07 18:17:40.000000000 -0700
@@ -642,7 +642,7 @@
 	res["current_player"] = id_.empty() ? current_player_ : id_;
 
 	if (id_.empty()) {
-		char const *description;
+		char const *description = NULL;
 		switch(controller_) {
 		case CNTR_NETWORK:
 			description = N_("(Vacant slot)");
