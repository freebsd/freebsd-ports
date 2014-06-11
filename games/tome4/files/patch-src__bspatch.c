--- ./src/bspatch.c.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/bspatch.c	2014-06-04 12:40:26.918305830 -0400
@@ -24,13 +24,13 @@
  * POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include "bzlib.h"
+#include <bzlib.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <err.h>
 #include <unistd.h>
 #include <fcntl.h>
-#include <sys/types.h>
 
 static off_t offtin(u_char *buf)
 {
@@ -50,13 +50,7 @@
 	return y;
 }
 
-#ifndef fseeko
-#define fseeko fseek
-#endif
-
-#define returnerr(ret, str, f1, f2) { printf(str, f1, f2); perror("\nError in bspatch\n"); return (ret); }
-
-int bspatch(char *infile, char *outfile, char *patchfile)
+int bspatch(int argc,char * argv[])
 {
 	FILE * f, * cpf, * dpf, * epf;
 	BZFILE * cpfbz2, * dpfbz2, * epfbz2;
@@ -71,9 +65,11 @@
 	off_t lenread;
 	off_t i;
 
+	if(argc!=4) errx(1,"usage: %s oldfile newfile patchfile\n",argv[0]);
+
 	/* Open patch file */
-	if ((f = fopen(patchfile, "r")) == NULL)
-		returnerr(1, "fopen(%s)", patchfile, 0);
+	if ((f = fopen(argv[3], "r")) == NULL)
+		err(1, "fopen(%s)", argv[3]);
 
 	/*
 	File format:
@@ -91,53 +87,54 @@
 
 	/* Read header */
 	if (fread(header, 1, 32, f) < 32) {
-		if (feof(f)) returnerr(1, "Corrupt patch", 0, 0);
-		returnerr(1, "fread(%s)", patchfile, 0);
+		if (feof(f))
+			errx(1, "Corrupt patch\n");
+		err(1, "fread(%s)", argv[3]);
 	}
 
 	/* Check for appropriate magic */
 	if (memcmp(header, "BSDIFF40", 8) != 0)
-		returnerr(1, "Corrupt patch", 0, 0);
+		errx(1, "Corrupt patch\n");
 
 	/* Read lengths from header */
 	bzctrllen=offtin(header+8);
 	bzdatalen=offtin(header+16);
 	newsize=offtin(header+24);
 	if((bzctrllen<0) || (bzdatalen<0) || (newsize<0))
-		returnerr(1, "Corrupt patch", 0, 0);
+		errx(1,"Corrupt patch\n");
 
 	/* Close patch file and re-open it via libbzip2 at the right places */
 	if (fclose(f))
-		returnerr(1, "fclose(%s)", patchfile, 0);
-	if ((cpf = fopen(patchfile, "r")) == NULL)
-		returnerr(1, "fopen(%s)", patchfile, 0);
+		err(1, "fclose(%s)", argv[3]);
+	if ((cpf = fopen(argv[3], "r")) == NULL)
+		err(1, "fopen(%s)", argv[3]);
 	if (fseeko(cpf, 32, SEEK_SET))
-		returnerr(1, "fseeko(%s, %lld)", patchfile,
+		err(1, "fseeko(%s, %lld)", argv[3],
 		    (long long)32);
 	if ((cpfbz2 = BZ2_bzReadOpen(&cbz2err, cpf, 0, 0, NULL, 0)) == NULL)
-		returnerr(1, "BZ2_bzReadOpen, bz2err = %d", cbz2err, 0);
-	if ((dpf = fopen(patchfile, "r")) == NULL)
-		returnerr(1, "fopen(%s)", patchfile, 0);
+		errx(1, "BZ2_bzReadOpen, bz2err = %d", cbz2err);
+	if ((dpf = fopen(argv[3], "r")) == NULL)
+		err(1, "fopen(%s)", argv[3]);
 	if (fseeko(dpf, 32 + bzctrllen, SEEK_SET))
-		returnerr(1, "fseeko(%s, %lld)", patchfile,
+		err(1, "fseeko(%s, %lld)", argv[3],
 		    (long long)(32 + bzctrllen));
 	if ((dpfbz2 = BZ2_bzReadOpen(&dbz2err, dpf, 0, 0, NULL, 0)) == NULL)
-		returnerr(1, "BZ2_bzReadOpen, bz2err = %d", dbz2err, 0);
-	if ((epf = fopen(patchfile, "r")) == NULL)
-		returnerr(1, "fopen(%s)", patchfile, 0);
+		errx(1, "BZ2_bzReadOpen, bz2err = %d", dbz2err);
+	if ((epf = fopen(argv[3], "r")) == NULL)
+		err(1, "fopen(%s)", argv[3]);
 	if (fseeko(epf, 32 + bzctrllen + bzdatalen, SEEK_SET))
-		returnerr(1, "fseeko(%s, %lld)", patchfile,
+		err(1, "fseeko(%s, %lld)", argv[3],
 		    (long long)(32 + bzctrllen + bzdatalen));
 	if ((epfbz2 = BZ2_bzReadOpen(&ebz2err, epf, 0, 0, NULL, 0)) == NULL)
-		returnerr(1, "BZ2_bzReadOpen, bz2err = %d", ebz2err, 0);
+		errx(1, "BZ2_bzReadOpen, bz2err = %d", ebz2err);
 
-	if(((fd=open(infile,O_RDONLY,0))<0) ||
+	if(((fd=open(argv[1],O_RDONLY,0))<0) ||
 		((oldsize=lseek(fd,0,SEEK_END))==-1) ||
 		((old=malloc(oldsize+1))==NULL) ||
 		(lseek(fd,0,SEEK_SET)!=0) ||
 		(read(fd,old,oldsize)!=oldsize) ||
-		(close(fd)==-1)) returnerr(1,"%s",infile, 0);
-	if((new=malloc(newsize+1))==NULL) returnerr(1,"not enough memory", 0, 0);
+		(close(fd)==-1)) err(1,"%s",argv[1]);
+	if((new=malloc(newsize+1))==NULL) err(1,NULL);
 
 	oldpos=0;newpos=0;
 	while(newpos<newsize) {
@@ -146,19 +143,19 @@
 			lenread = BZ2_bzRead(&cbz2err, cpfbz2, buf, 8);
 			if ((lenread < 8) || ((cbz2err != BZ_OK) &&
 			    (cbz2err != BZ_STREAM_END)))
-				returnerr(1, "Corrupt patch", 0, 0);
+				errx(1, "Corrupt patch\n");
 			ctrl[i]=offtin(buf);
 		};
 
 		/* Sanity-check */
 		if(newpos+ctrl[0]>newsize)
-			returnerr(1, "Corrupt patch", 0, 0);
+			errx(1,"Corrupt patch\n");
 
 		/* Read diff string */
 		lenread = BZ2_bzRead(&dbz2err, dpfbz2, new + newpos, ctrl[0]);
 		if ((lenread < ctrl[0]) ||
 		    ((dbz2err != BZ_OK) && (dbz2err != BZ_STREAM_END)))
-			returnerr(1, "Corrupt patch", 0, 0);
+			errx(1, "Corrupt patch\n");
 
 		/* Add old data to diff string */
 		for(i=0;i<ctrl[0];i++)
@@ -171,13 +168,13 @@
 
 		/* Sanity-check */
 		if(newpos+ctrl[1]>newsize)
-			returnerr(1, "Corrupt patch", 0, 0);
+			errx(1,"Corrupt patch\n");
 
 		/* Read extra string */
 		lenread = BZ2_bzRead(&ebz2err, epfbz2, new + newpos, ctrl[1]);
 		if ((lenread < ctrl[1]) ||
 		    ((ebz2err != BZ_OK) && (ebz2err != BZ_STREAM_END)))
-			returnerr(1, "Corrupt patch", 0, 0);
+			errx(1, "Corrupt patch\n");
 
 		/* Adjust pointers */
 		newpos+=ctrl[1];
@@ -189,12 +186,12 @@
 	BZ2_bzReadClose(&dbz2err, dpfbz2);
 	BZ2_bzReadClose(&ebz2err, epfbz2);
 	if (fclose(cpf) || fclose(dpf) || fclose(epf))
-		returnerr(1, "fclose(%s)", patchfile, 0);
+		err(1, "fclose(%s)", argv[3]);
 
 	/* Write the new file */
-	if(((fd=open(outfile,O_CREAT|O_TRUNC|O_WRONLY,0666))<0) ||
+	if(((fd=open(argv[2],O_CREAT|O_TRUNC|O_WRONLY,0666))<0) ||
 		(write(fd,new,newsize)!=newsize) || (close(fd)==-1))
-		returnerr(1,"%s",outfile, 0);
+		err(1,"%s",argv[2]);
 
 	free(new);
 	free(old);
