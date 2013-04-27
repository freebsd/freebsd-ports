--- jpeg2ps.c.orig	2013-04-27 23:19:06.000000000 +0900
+++ jpeg2ps.c	2013-04-27 23:32:17.000000000 +0900
@@ -73,6 +73,13 @@
 static char buffer[BUFFERSIZE];
 static char *ColorSpaceNames[] = {"", "Gray", "", "RGB", "CMYK" };
 
+#ifdef LIBPAPER
+#include <math.h>
+#include <paper.h>
+
+int PageWidth  = 595;           /* page width A4 */
+int PageHeight = 842;           /* page height A4 */
+#else
 /* Array of known page sizes including name, width, and height */
 
 typedef struct { const char *name; int width; int height; } PageSize_s;
@@ -104,6 +111,7 @@
 int PageWidth  = 612;           /* page width letter */
 int PageHeight = 792;           /* page height letter */
 #endif
+#endif
 
 static void 
 JPEGtoPS(imagedata *JPEG, FILE *PSfile) {
@@ -294,16 +302,39 @@
   fprintf(stderr, "-b        binary mode: output 8 bit data (default: 7 bit with ASCII85)\n");
   fprintf(stderr, "-h        hex mode: output 7 bit data in ASCIIHex encoding\n");
   fprintf(stderr, "-o <name> output file name\n");
+#ifdef LIBPAPER
+  fprintf(stderr, "-p <size> page size name. Known names can be displayed "
+                  "by paperconf -a command.\n");
+#else
   fprintf(stderr, "-p <size> page size name. Known names are:\n");
   fprintf(stderr, "          a0, a1, a2, a3, a4, a5, a6, b5, letter, legal, ledger, p11x17\n");
+#endif
   fprintf(stderr, "-q        quiet mode: suppress all informational messages\n");
   fprintf(stderr, "-r <dpi>  resolution value (dots per inch)\n");
   fprintf(stderr, "          0 means use value given in file, if any (disables autorotate)\n");
   exit(1);
 }
 
+#ifdef LIBPAPER
+const struct paper *findpaper(char *name)
+{
+	const struct paper *pp;
+
+	paperinit();
+	for (pp = paperfirst(); pp; pp = papernext(pp)) {
+		if (strcmp(name, papername(pp)) == 0)
+			return (pp);
+	}
+	return (NULL);
+}
+#endif
+
 int
 main(int argc, char ** argv) {
+#ifdef LIBPAPER
+  const struct paper *pp;
+  char *name = NULL;
+#endif
   imagedata image;
   FILE *outfile;
 
@@ -346,6 +377,9 @@
 	  } 
 	  break;
       case 'p':
+#ifdef LIBPAPER
+	  name = strdup(optarg);
+#else
 	  for(pagesizeindex=0; pagesizeindex < PAGESIZELIST; pagesizeindex++)
 	    if (!strcmp((const char *) optarg, PageSizes[pagesizeindex].name)) {
 		PageHeight = PageSizes[pagesizeindex].height;
@@ -356,6 +390,7 @@
 		fprintf(stderr, "Error: Unknown page size %s.\n", optarg);
 		exit(-3);
 	  }
+#endif
 	  break;
       case 'q':
           quiet = TRUE;
@@ -371,9 +406,24 @@
 	  usage();
     }
 
+#ifdef LIBPAPER
+  if (name == NULL) {
+	name = (char *)systempapername();
+	if (name == NULL)
+		name = (char *)defaultpapername();
+  }
+  if ((pp = findpaper(name)) != NULL) {
+	PageHeight = round(paperpsheight(pp));
+	PageWidth = round(paperpswidth(pp));
+  } else {
+	fprintf(stderr, "Error: Unknown page size %s.\n", name);
+	exit(-3);
+  }
+#else
   if (pagesizeindex != -1 && ! quiet)	/* page size user option given */
       fprintf(stderr, "Note: Using %s page size.\n",
 		    PageSizes[pagesizeindex].name);
+#endif
 
   if (optind == argc)	/* filename missing */
     usage();
