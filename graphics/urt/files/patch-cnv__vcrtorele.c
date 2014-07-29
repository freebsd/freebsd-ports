--- cnv/vcrtorle.c.orig	Thu Mar 10 20:22:42 2005
+++ cnv/vcrtorle.c	Thu Mar 10 20:30:16 2005
@@ -94,9 +94,6 @@
 
 
 static int VERBOSE = 0;
-static char *RoutineName;
-
-static long int VICARpos;	/* Position in file for reading w/o fseek. */
 
 static void FatalError(s)
  char *s;
@@ -109,20 +106,10 @@
 static int  LBLSIZE;       /* size of header, must be int mult of NS */
 static char FORMAT[80];    /* 'BYTE' is OK */
 static char TYPE[80];      /* 'IMAGE' is OK */
-static int  BUFSIZe;       /* integer multiple of NS ? */
-static int  DIM;           /* == 3? */
-static int  EOL;           /* == 0? */
-static int  RECSIZE;       /* == LBLSIZE? */
 static char ORG[80];       /* `BSQ` is OK */
 static int  NL;            /* height */
 static int  NS;            /* width */ 
 static int  NB;            /* samples per pixel? */
-static int  N1;            /* == NL? */ 
-static int  N2;            /* == NS? */
-static int  N3;            /* == NB? */
-static int  N4;            /* 0 is OK */
-static int  NBB;           /* 0 is OK */ 
-static int  NLB;           /* 0 is OK */
 static char HOST[80];      /* machine type? */
 static char INTFMT[80];    /* integer format? */
 static char REALFMT[80];   /* real format? */
@@ -218,20 +205,20 @@
 
 	if (0 == strcmp("FORMAT" ,Name)) {strcpy(FORMAT ,Value); continue;} 
 	if (0 == strcmp("TYPE"   ,Name)) {strcpy(TYPE   ,Value); continue;} 
-	if (0 == strcmp("BUFSIZ" ,Name)) {BUFSIZe = atoi(Value); continue;}
-	if (0 == strcmp("DIM"    ,Name)) {DIM     = atoi(Value); continue;}
-	if (0 == strcmp("EOL"    ,Name)) {EOL     = atoi(Value); continue;}
-	if (0 == strcmp("RECSIZE",Name)) {RECSIZE = atoi(Value); continue;}
+	if (0 == strcmp("BUFSIZ" ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("DIM"    ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("EOL"    ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("RECSIZE",Name)) { (void) atoi(Value); continue;}
 	if (0 == strcmp("ORG"    ,Name)) {strcpy(ORG    ,Value); continue;} 
 	if (0 == strcmp("NL"     ,Name)) {NL      = atoi(Value); continue;}
 	if (0 == strcmp("NS"     ,Name)) {NS      = atoi(Value); continue;}
 	if (0 == strcmp("NB"     ,Name)) {NB      = atoi(Value); continue;}
-	if (0 == strcmp("N1"     ,Name)) {N1      = atoi(Value); continue;}
-	if (0 == strcmp("N2"     ,Name)) {N2      = atoi(Value); continue;}
-	if (0 == strcmp("N3"     ,Name)) {N3      = atoi(Value); continue;}
-	if (0 == strcmp("N4"     ,Name)) {N4      = atoi(Value); continue;}
-	if (0 == strcmp("NBB"    ,Name)) {NBB     = atoi(Value); continue;}
-	if (0 == strcmp("NLB"    ,Name)) {NLB     = atoi(Value); continue;}
+	if (0 == strcmp("N1"     ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("N2"     ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("N3"     ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("N4"     ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("NBB"    ,Name)) { (void) atoi(Value); continue;}
+	if (0 == strcmp("NLB"    ,Name)) { (void) atoi(Value); continue;}
 	if (0 == strcmp("HOST"   ,Name)) {strcpy(HOST   ,Value); continue;} 
 	if (0 == strcmp("INTFMT" ,Name)) {strcpy(INTFMT ,Value); continue;} 
 	if (0 == strcmp("REALFMT",Name)) {strcpy(REALFMT,Value); continue;} 
@@ -249,7 +236,6 @@
 	n++;
     }
 	
-    VICARpos = n;
 }
 
 /* RLE stuff */
@@ -297,7 +283,7 @@
     unsigned char *VICARImage;
     char *outfname = NULL;
     int oflag = 0;
-    int x,y,z;
+    int y;
     long int nread;
     rle_hdr the_hdr;
     rle_pixel **rows;
