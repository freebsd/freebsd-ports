--- src/unshar.c.orig	1995-11-21 17:22:14.000000000 +0100
+++ src/unshar.c	2004-09-29 15:09:44.682469264 +0200
@@ -346,8 +346,8 @@
 {
   size_t size_read;
   FILE *file;
-  char name_buffer[NAME_BUFFER_SIZE];
-  char copy_buffer[NAME_BUFFER_SIZE];
+  char name_buffer[NAME_BUFFER_SIZE] = {'\0'};
+  char copy_buffer[NAME_BUFFER_SIZE] = {'\0'};
   int optchar;
 
   program_name = argv[0];
@@ -409,14 +409,14 @@
   if (optind < argc)
     for (; optind < argc; optind++)
       {
-	if (argv[optind][0] == '/')
-	  stpcpy (name_buffer, argv[optind]);
-	else
-	  {
-	    char *cp = stpcpy (name_buffer, current_directory);
-	    *cp++ = '/';
-	    stpcpy (cp, argv[optind]);
-	  }
+	if (argv[optind][0] == '/') {
+		strncpy (name_buffer, argv[optind], sizeof(name_buffer));
+		name_buffer[sizeof(name_buffer)-1] = '\0';
+	}
+	else {
+		snprintf(name_buffer, sizeof(name_buffer),"%s/%s", current_directory, argv[optind]);
+		name_buffer[sizeof(name_buffer)-1] = '\0';
+	}
 	if (file = fopen (name_buffer, "r"), !file)
 	  error (EXIT_FAILURE, errno, name_buffer);
 	unarchive_shar_file (name_buffer, file);
