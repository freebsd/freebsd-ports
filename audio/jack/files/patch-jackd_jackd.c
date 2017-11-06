--- jackd/jackd.c.orig	2017-07-17 17:10:09 UTC
+++ jackd/jackd.c
@@ -521,11 +521,17 @@ jack_drivers_load ()
 
 static void copyright (FILE* file)
 {
-	fprintf (file, "jackd " VERSION "\n"
+	fprintf (file, "jackd " VERSION " (COOKEDMODE=%s)\n"
 		 "Copyright 2001-2009 Paul Davis, Stephane Letz, Jack O'Quinn, Torben Hohn and others.\n"
 		 "jackd comes with ABSOLUTELY NO WARRANTY\n"
 		 "This is free software, and you are welcome to redistribute it\n"
-		 "under certain conditions; see the file COPYING for details\n\n");
+		 "under certain conditions; see the file COPYING for details\n\n",
+#if defined(OPTION_COOKEDMODE)
+                 "on"
+#else
+                 "off"
+#endif
+                 );
 }
 
 static void usage (FILE *file)
