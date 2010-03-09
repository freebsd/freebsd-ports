--- nwreckdu.c.orig	Mon Jun  8 17:47:02 1998
+++ nwreckdu.c	Fri Nov  3 02:30:05 2006
@@ -23,11 +23,11 @@
 
 typedef struct {
 	char	name[56];
-	unsigned long	offset, length;
+	uint32_t	offset, length;
 } dirrec;
 
 int	asmpak(FILE *);
-int	extrpak(FILE *);
+int	extrpak(FILE *, int);
 int	write_rec(dirrec, FILE *);
 int	makepath(char *);
 
@@ -37,6 +37,7 @@
 "\n"
 "  -c, --create		create PACK instead of extracting\n"
 "  -d, --dir=DIR	use DIR as the input/output directory\n"
+"  -l, --list		list files stored in PACK\n"
 "  -h, --help		display this help\n"
 "  -p, --pak=FILE	read FILE for PACK information\n"
 "\n"
@@ -47,7 +48,7 @@
 
 int	main(int argc, char **argv) {
 	FILE	*pakhand = NULL;
-	int	makepak = 0;
+	int	makepak = 0, listpak = 0;
 	char	*pakfile = NULL, *outdir = NULL;
 	const char	defpakfile[] = "pak0.pak",
 			defoutdir[] = "pak0";
@@ -55,6 +56,7 @@
 		{ 'p', "pak",	OPT_STRING,	&pakfile,	0 },
 		{ 'd', "dir",	OPT_STRING,	&outdir,	0 },
 		{ 'c', "create", OPT_FLAG,	&makepak,	0 },
+		{ 'l', "list",	OPT_FLAG,	&listpak,	0 },
 		{ 'h', "help",	OPT_FLAG,	usage,	OPT_CALLFUNC },
 		{ 0,   NULL,	OPT_END,	0,		0 }
 	};
@@ -66,8 +68,9 @@
 		outdir = (char *)defoutdir;
 
 	printf("Using pak file: %s\n", pakfile);
-	printf("Input/output directory: %s\n", outdir);
-	printf("Operation: %s\n", (makepak?"create":"extract"));
+	if (!listpak)
+		printf("Input/output directory: %s\n", outdir);
+	printf("Operation: %s\n", (makepak?"create":listpak?"list":"extract"));
 
 	if (makepak)
 		pakhand = fopen(pakfile, "wb");
@@ -79,6 +82,8 @@
 		return(-1);
 	}
 
+	if (!listpak) {
+
 	if (!makepak && (mkdir(outdir, 493 /*octal=755*/) == -1)) {
 		printf("Error making %s: %s\n", outdir, strerror(errno));
 		fclose(pakhand);
@@ -89,12 +94,12 @@
 			strerror(errno));
 		fclose(pakhand);
 		return(-1);
-	}
+	} }
 
 	if (makepak)
 		asmpak(pakhand);
 	else
-		extrpak(pakhand);
+		extrpak(pakhand, listpak);
 
 	fclose(pakhand);
 	return(0);
@@ -209,7 +214,7 @@
 	return(1);
 }
 
-int	extrpak(FILE *in) {
+int	extrpak(FILE *in, int listpak) {
 	dirrec	*dir = NULL;
 	char	signature[4];
 	unsigned long	dir_start = 0, num_ents = 0;
@@ -244,6 +249,8 @@
 	for (i = 0; i < num_ents; i++) {
 		printf("%3i %8lu %s\n", i, dir[i].length, 
 			dir[i].name);
+		if (listpak)
+			continue;
 		if (write_rec(dir[i], in))
 			printf("Error writing record: %s\n",
 				strerror(errno));
