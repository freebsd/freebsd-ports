--- ./src/CoverGetter.cs.orig	2012-04-04 21:27:24.000000000 -0400
+++ ./src/CoverGetter.cs	2012-04-04 21:28:50.000000000 -0400
@@ -53,7 +53,7 @@
 		// Variables
 		private string amazon_locale;
 		private string amazon_dev_tag;
-		private bool musicbrainz_lib_missing = false;
+		private bool musicbrainz_lib_missing = true;
 		private bool amazon_dev_tag_missing = false;
 
 		// Variables :: Cover Filenames
