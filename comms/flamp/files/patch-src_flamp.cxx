--- src/flamp.cxx.orig	2020-02-08 03:11:19 UTC
+++ src/flamp.cxx
@@ -838,7 +838,7 @@ void addfile(std::string xmtfname, void *rx, bool useC
 	int use_comp_on_file = 0;
 	int use_forced_comp_on_file = 0;
 
-	if(rx > 0 && !rAmp->rx_completed()) {
+	if(rx != nullptr && !rAmp->rx_completed()) {
 		fl_alert2("Only completed files can be transfered");
 		return;
 	}
@@ -934,7 +934,7 @@ void addfile(std::string xmtfname, void *rx, bool useC
 
 	LOG_INFO("File added to transmit queue: %s", xmtfname.c_str());
 
-	if(rx > 0) {
+	if(rx != nullptr) {
 		cAmp *rAmp = (cAmp *) rx;
 		int xfrBlockSize = rAmp->rx_blocksize_int();
 
@@ -2649,7 +2649,7 @@ int parse_args(int argc, char **argv, int& idx)
 
 
 	if (strcasecmp(argv[idx], "--version") == 0) {
-		printf("Version: "VERSION"\n");
+		printf("Version: " VERSION "\n");
 		exit (0);
 	}
 	return 0;
