--- h2patch/h2patch3.c.orig	2017-09-01 18:03:15 UTC
+++ h2patch/h2patch3.c
@@ -580,6 +580,7 @@ static void print_help (void)
 	fprintf (stdout, "  -h | -help   show help\n");
 	fprintf (stdout, "  -version     show version\n");
 	fprintf (stdout, "  -verbose     be verbose\n");
+	fprintf (stdout, "  -prefix dir  look for data files in 'dir'\n");
 }
 
 
@@ -663,6 +664,7 @@ int main (int argc, char **argv)
 	int	i, num_patched, ret;
 	long		len;
 	unsigned long	csum;
+	char*	prefix = ".";
 
 	print_version ();
 	for (i = 1; i < argc; ++i)
@@ -680,6 +682,10 @@ int main (int argc, char **argv)
 		{
 			h2patch_options.verbose = 1;
 		}
+		else if (!strcmp(argv[i], "-prefix"))
+		{
+			prefix = argv[++i];
+		}
 		else
 		{
 			fprintf (stderr, "Unrecognized option \"%s\"\n", argv[i]);
@@ -710,8 +716,8 @@ int main (int argc, char **argv)
 
 	for (i = 0; i < NUM_PATCHES; i++)
 	{
-		q_snprintf (dst, sizeof(dst), "%s%c%s", patch_data[i].dir_name,
-					DIR_SEPARATOR_CHAR, patch_data[i].filename);
+		q_snprintf (dst, sizeof(dst), "%s%c%s%c%s", prefix , DIR_SEPARATOR_CHAR, 
+			patch_data[i].dir_name, DIR_SEPARATOR_CHAR, patch_data[i].filename);
 		fprintf (stdout, "File %s :\n", dst);
 
 		ret = check_access(dst);
