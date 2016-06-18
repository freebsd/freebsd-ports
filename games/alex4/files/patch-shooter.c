--- shooter.c.orig	2016-06-14 16:25:53 UTC
+++ shooter.c
@@ -1372,7 +1372,7 @@ int s_init_shooter() {
 	// load data
 	log2file(" loading shooter data");
 	packfile_password(get_init_string());
-	s_data = load_datafile("data/a45.dat");
+	s_data = load_datafile(DATADIR "a45.dat");
 	if (!s_data) {
 		log2file(" *** failed");
 		return -1;
